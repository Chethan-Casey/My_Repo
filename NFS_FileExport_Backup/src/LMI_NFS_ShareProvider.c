/* Copyright (C) 2013-14 Green Turtles Technologies <www.greenturtles.in>, Inc.  All rights reserved.

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors: Chethan Y <chethan.casey@gmail.com>
            Hemanth Kumar HC <hemanthkumar51@gmail.com>
 * -*- coding: utf-8 -*-
 */


#include <konkret/konkret.h>
#include <sys/stat.h>
#include "LMI_NFS_Share.h"
#include "export.c"

static const CMPIBroker* _cb = NULL;

static void LMI_NFS_ShareInitialize()
{

}

static CMPIStatus LMI_NFS_ShareCleanup(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    CMPIBoolean term)
{
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFS_ShareEnumInstanceNames(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop)
{
    return KDefaultEnumerateInstanceNames(
        _cb, mi, cc, cr, cop);
}

static CMPIStatus LMI_NFS_ShareEnumInstances(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char** properties)
{


    LMI_NFS_Share s;
    struct stat st;
    LMI_NFS_Share_Init(&s, _cb, KNameSpace (cop));
    int i;
    char buf[256];
    struct nfs *exportinfo = malloc(sizeof(struct nfs));
    exportinfo=Get_Export_List();
    for(i=0;i<exportinfo->countshare;i++) {
		snprintf(buf, sizeof buf,"%s:%d[of(%d)]", "NFSShare",i+1, exportinfo->countshare);
        LMI_NFS_Share_Set_InstanceID(&s, buf);
        LMI_NFS_Share_Set_ElementName(&s, "Nfs Share");
        LMI_NFS_Share_Set_Name(&s, exportinfo->share[i]);
    	LMI_NFS_Share_Init_OperationalStatus(&s, 1);
        	if ( stat(exportinfo->share[i], &st) == 0 ) {
	    		if(S_ISDIR(st.st_mode))
                	LMI_NFS_Share_Set_SharingDirectory(&s, 1);
            	else
                	LMI_NFS_Share_Set_SharingDirectory(&s, 0);   
        		LMI_NFS_Share_Set_OperationalStatus(&s, 0, 2 );
		}
        else 
			LMI_NFS_Share_Set_OperationalStatus(&s, 0, LMI_NFS_Share_OperationalStatus_Error ); 
    	KReturnInstance(cr, s);
    }
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFS_ShareGetInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char** properties)
{
    return KDefaultGetInstance(
        _cb, mi, cc, cr, cop, properties);
}

static CMPIStatus LMI_NFS_ShareCreateInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const CMPIInstance* ci)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFS_ShareModifyInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const CMPIInstance* ci,
    const char** properties)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFS_ShareDeleteInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFS_ShareExecQuery(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* lang,
    const char* query)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

CMInstanceMIStub(
    LMI_NFS_Share,
    LMI_NFS_Share,
    _cb,
    LMI_NFS_ShareInitialize())

static CMPIStatus LMI_NFS_ShareMethodCleanup(
    CMPIMethodMI* mi,
    const CMPIContext* cc,
    CMPIBoolean term)
{
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFS_ShareInvokeMethod(
    CMPIMethodMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* meth,
    const CMPIArgs* in,
    CMPIArgs* out)
{
    return LMI_NFS_Share_DispatchMethod(
        _cb, mi, cc, cr, cop, meth, in, out);
}

CMMethodMIStub(
    LMI_NFS_Share,
    LMI_NFS_Share,
    _cb,
    LMI_NFS_ShareInitialize())

KUint32 LMI_NFS_Share_RequestStateChange(
    const CMPIBroker* cb,
    CMPIMethodMI* mi,
    const CMPIContext* context,
    const LMI_NFS_ShareRef* self,
    const KUint16* RequestedState,
    KRef* Job,
    const KDateTime* TimeoutPeriod,
    CMPIStatus* status)
{
    KUint32 result = KUINT32_INIT;

    KSetStatus(status, ERR_NOT_SUPPORTED);
    return result;
}

KONKRET_REGISTRATION(
    "root/cimv2",
    "LMI_NFS_Share",
    "LMI_NFS_Share",
    "instance method")

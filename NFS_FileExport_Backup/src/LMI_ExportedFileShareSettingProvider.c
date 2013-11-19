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
#include "LMI_ExportedFileShareSetting.h"
#include <sys/stat.h>
#include "export.h"
#ifndef EXPORT_C
#define EXPORT_C
#endif
static const CMPIBroker* _cb = NULL;

static void LMI_ExportedFileShareSettingInitialize()
{
}

static CMPIStatus LMI_ExportedFileShareSettingCleanup(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    CMPIBoolean term)
{
	CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_ExportedFileShareSettingEnumInstanceNames(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop)
{
    return KDefaultEnumerateInstanceNames(
        _cb, mi, cc, cr, cop);
}

static CMPIStatus LMI_ExportedFileShareSettingEnumInstances(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char** properties)
{
    char buf[250];
    int i;
    LMI_ExportedFileShareSetting s;
    struct nfs *exportinfo = malloc(sizeof(struct nfs));
    exportinfo=Get_Export_List();
    LMI_ExportedFileShareSetting_Init(&s, _cb, KNameSpace (cop));
	for(i=0;i<exportinfo->countshare;i++) {
	    snprintf(buf, sizeof buf,"%s:%d[of(%d)]", "NFSExportedFileShareSetting",i+1, exportinfo->countshare);
	    LMI_ExportedFileShareSetting_Set_InstanceID(&s, buf);
	    LMI_ExportedFileShareSetting_Set_FileSharingProtocol(&s,2);
    /*Set up Protocol Version
            LMI_ExportedFileShareSetting_Init_ProtocolVersions(&s,1);  
            LMI_ExportedFileShareSetting_Set_ProtocolVersions(&s, 0, "value");
    */
     	KReturnInstance(cr, s);
    }
    CMReturn(CMPI_RC_OK);
}
static CMPIStatus LMI_ExportedFileShareSettingGetInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char** properties)
{
    return KDefaultGetInstance(
        _cb, mi, cc, cr, cop, properties);
}

static CMPIStatus LMI_ExportedFileShareSettingCreateInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const CMPIInstance* ci)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_ExportedFileShareSettingModifyInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const CMPIInstance* ci,
    const char** properties)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_ExportedFileShareSettingDeleteInstance(
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop)
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_ExportedFileShareSettingExecQuery(
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
    LMI_ExportedFileShareSetting,
    LMI_ExportedFileShareSetting,
    _cb,
    LMI_ExportedFileShareSettingInitialize())

static CMPIStatus LMI_ExportedFileShareSettingMethodCleanup(
    CMPIMethodMI* mi,
    const CMPIContext* cc,
    CMPIBoolean term)
{
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_ExportedFileShareSettingInvokeMethod(
    CMPIMethodMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* meth,
    const CMPIArgs* in,
    CMPIArgs* out)
{
    return LMI_ExportedFileShareSetting_DispatchMethod(
        _cb, mi, cc, cr, cop, meth, in, out);
}

CMMethodMIStub(
    LMI_ExportedFileShareSetting,
    LMI_ExportedFileShareSetting,
    _cb,
    LMI_ExportedFileShareSettingInitialize())

KONKRET_REGISTRATION(
    "root/cimv2",
    "LMI_ExportedFileShareSetting",
    "LMI_ExportedFileShareSetting",
    "instance method")

#include <konkret/konkret.h>
#include "LMI_NFSElementSettingData.h"
#include "export.h"
#ifndef EXPORT_C
#define EXPORT_C
#endif
static const CMPIBroker* _cb;

static void LMI_NFSElementSettingDataInitialize()
{
}

static CMPIStatus LMI_NFSElementSettingDataCleanup( 
    CMPIInstanceMI* mi,
    const CMPIContext* cc, 
    CMPIBoolean term)
{
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFSElementSettingDataEnumInstanceNames( 
    CMPIInstanceMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop)
{
    return KDefaultEnumerateInstanceNames(
        _cb, mi, cc, cr, cop);
}

static CMPIStatus LMI_NFSElementSettingDataEnumInstances( 
    CMPIInstanceMI* mi,
    const CMPIContext* cc, 
    const CMPIResult* cr, 
    const CMPIObjectPath* cop, 
    const char** properties) 
{
    int i;
    char buf[250];
    LMI_NFSElementSettingData n;
    LMI_NFSElementSettingData_Init(&n, _cb, KNameSpace (cop));
  
    LMI_NFS_ShareRef nfsref;
    LMI_NFS_ShareRef_Init(&nfsref, _cb, KNameSpace (cop));
    
    LMI_ExportedFileShareSettingRef fileref;
    LMI_ExportedFileShareSettingRef_Init(&fileref, _cb, KNameSpace (cop));
 
    struct nfs *exportinfo = malloc(sizeof(struct nfs));
    exportinfo=get_export_list();
    for(i=0;i<exportinfo->countshare;i++)
    {
     snprintf(buf, sizeof buf,"%s:%d[of(%d)]", "NFSShare",i+1, exportinfo->countshare);
    LMI_NFS_ShareRef_Set_InstanceID(&nfsref, buf);
    snprintf(buf, sizeof buf,"%s:%d[of(%d)]", "NFSExportedFileShareSetting",i+1, exportinfo->countshare);
    LMI_ExportedFileShareSettingRef_Set_InstanceID(&fileref, buf);
    LMI_NFSElementSettingData_Set_Share(&n, &nfsref);
    LMI_NFSElementSettingData_Set_ShareSetting(&n, &fileref);
    KReturnInstance(cr, n);
    }

    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFSElementSettingDataGetInstance( 
    CMPIInstanceMI* mi, 
    const CMPIContext* cc,
    const CMPIResult* cr, 
    const CMPIObjectPath* cop, 
    const char** properties) 
{
    return KDefaultGetInstance(
        _cb, mi, cc, cr, cop, properties);
}

static CMPIStatus LMI_NFSElementSettingDataCreateInstance( 
    CMPIInstanceMI* mi, 
    const CMPIContext* cc, 
    const CMPIResult* cr, 
    const CMPIObjectPath* cop, 
    const CMPIInstance* ci) 
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFSElementSettingDataModifyInstance( 
    CMPIInstanceMI* mi, 
    const CMPIContext* cc, 
    const CMPIResult* cr, 
    const CMPIObjectPath* cop,
    const CMPIInstance* ci, 
    const char**properties) 
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFSElementSettingDataDeleteInstance( 
    CMPIInstanceMI* mi, 
    const CMPIContext* cc, 
    const CMPIResult* cr, 
    const CMPIObjectPath* cop) 
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFSElementSettingDataExecQuery(
    CMPIInstanceMI* mi, 
    const CMPIContext* cc, 
    const CMPIResult* cr, 
    const CMPIObjectPath* cop, 
    const char* lang, 
    const char* query) 
{
    CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

static CMPIStatus LMI_NFSElementSettingDataAssociationCleanup( 
    CMPIAssociationMI* mi,
    const CMPIContext* cc, 
    CMPIBoolean term) 
{
    CMReturn(CMPI_RC_OK);
}

static CMPIStatus LMI_NFSElementSettingDataAssociators(
    CMPIAssociationMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* assocClass,
    const char* resultClass,
    const char* role,
    const char* resultRole,
    const char** properties)
{
    return KDefaultAssociators(
        _cb,
        mi,
        cc,
        cr,
        cop,
        LMI_NFSElementSettingData_ClassName,
        assocClass,
        resultClass,
        role,
        resultRole,
        properties);
}

static CMPIStatus LMI_NFSElementSettingDataAssociatorNames(
    CMPIAssociationMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* assocClass,
    const char* resultClass,
    const char* role,
    const char* resultRole)
{
    return KDefaultAssociatorNames(
        _cb,
        mi,
        cc,
        cr,
        cop,
        LMI_NFSElementSettingData_ClassName,
        assocClass,
        resultClass,
        role,
        resultRole);
}

static CMPIStatus LMI_NFSElementSettingDataReferences(
    CMPIAssociationMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* assocClass,
    const char* role,
    const char** properties)
{
    return KDefaultReferences(
        _cb,
        mi,
        cc,
        cr,
        cop,
        LMI_NFSElementSettingData_ClassName,
        assocClass,
        role,
        properties);
}

static CMPIStatus LMI_NFSElementSettingDataReferenceNames(
    CMPIAssociationMI* mi,
    const CMPIContext* cc,
    const CMPIResult* cr,
    const CMPIObjectPath* cop,
    const char* assocClass,
    const char* role)
{
    return KDefaultReferenceNames(
        _cb,
        mi,
        cc,
        cr,
        cop,
        LMI_NFSElementSettingData_ClassName,
        assocClass,
        role);
}

CMInstanceMIStub( 
    LMI_NFSElementSettingData,
    LMI_NFSElementSettingData,
    _cb,
    LMI_NFSElementSettingDataInitialize())

CMAssociationMIStub( 
    LMI_NFSElementSettingData,
    LMI_NFSElementSettingData,
    _cb,
    LMI_NFSElementSettingDataInitialize())

KONKRET_REGISTRATION(
    "root/cimv2",
    "LMI_NFSElementSettingData",
    "LMI_NFSElementSettingData",
    "instance association")

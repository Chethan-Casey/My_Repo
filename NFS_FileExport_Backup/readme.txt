/* Checking The Exported Nfs file shares on the System */

-> Traverse to NFS_FileExport Dir

-> Traverse to build dir & cmake
      cmake ..

-> Use make & make install

-> Register the provider
   openlmi-mof-register -v 0.0.25 register ../mof/nfs.mof src/nfs.reg

-> Open Yawn Browser & Check Whether all the classes are functioning properly.
    LMI_NFS_Share (class) -> displays all the file shares 
    LMI_ExportedFileShareSetting (class) -> displays the properties of file shares
    LMI_NFSElementSettingData (Association) 

/* Any queries or suggestions is acceptable */

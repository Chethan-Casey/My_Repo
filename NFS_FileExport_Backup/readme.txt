/* File Export Sub Profile
Checking The Exported Nfs File Shares Available on the System */



     LMI_NFS_Share ---------------------- LMI_ExportedFileShareSetting
        (class)              |                     (class)
                             |
                  LMI_NFSElementSettingData                  
                       (Association)


Steps to be followed :-

-> Traverse to NFS_FileExport Dir

-> Traverse to build dir & cmake
      cmake ..

-> Use make & make install

-> Register the provider
   openlmi-mof-register -v 0.0.25 register ../mof/nfs.mof src/nfs.reg
   /* To unregister the provider
    openlmi-mof-register -v 0.0.25 unregister ../mof/nfs.mof src/nfs.reg
   */

-> Open Yawn in Browser & Check Whether all the classes are functioning properly.
    LMI_NFS_Share (class) -> Displays all the NFS File Shares 
    LMI_ExportedFileShareSetting (class) -> Displays the properties of NFS File Shares
    LMI_NFSElementSettingData (Association) -> Association class between LMI_NFS_Share & LMI_ExportedFileShareSetting

         /* Any queries or suggestions is acceptable */

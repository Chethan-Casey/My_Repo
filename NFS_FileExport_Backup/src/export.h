#ifndef EXPORT_H
#define EXPORT_H
char* getversion();
struct nfs* get_export_list(int*);
struct nfs{
  char ***share;
  int countshare;
};

#endif /* export.h */

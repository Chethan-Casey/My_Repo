#ifndef EXPORT_H
#define EXPORT_H

struct nfs* Get_Export_List();
char* getversion();
struct nfs {
  char **share;
  int countshare;
};

#endif /* export.h */

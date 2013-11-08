#ifndef EXPORT_H
#define EXPORT_H

struct nfs* get_export_list();
struct nfs {
  char **share;
  int countshare;
};

#endif /* export.h */

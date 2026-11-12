#ifndef _PINFO_H_
#define _PINFO_H_

struct pinfo {
  int pid;
  int state;
  int level;
  int runticks;
  int nsched;
  int ctime;
  char name[16];
};

#endif


#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int
main(void)
{
  struct pinfo processes[64];

  int count = getpinfo(processes, 64);

  if(count < 0) {
    printf("getpinfo failed\n");
    exit(1);
  }

  printf("PID\tSTATE\tLEVEL\tTICKS\tSCHED\tCTIME\tNAME\n");

  for(int i = 0; i < count; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
           processes[i].pid,
           processes[i].state,
           processes[i].level,
           processes[i].runticks,
           processes[i].nsched,
           processes[i].ctime,
           processes[i].name);
  }

  exit(0);
}

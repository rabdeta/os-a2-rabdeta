
#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pinfo.h"
#include "user/user.h"

int
main(void)
{
  int pid = getpid();
  struct pinfo info[64];

  printf("Starting CPU-intensive test (PID %d)\n", pid);

  for(volatile unsigned long i = 0; i < 100000000UL; i++) {
    // Keep CPU busy.
  }

  int count = getpinfo(info, 64);

  if(count < 0) {
    printf("getpinfo failed\n");
    exit(1);
  }

  for(int i = 0; i < count; i++) {
    if(info[i].pid == pid) {
      printf("PID: %d\n", info[i].pid);
      printf("Level: %d\n", info[i].level);
      printf("Runtime ticks: %d\n", info[i].runticks);
      printf("Times scheduled: %d\n", info[i].nsched);
    }
  }

  exit(0);
}

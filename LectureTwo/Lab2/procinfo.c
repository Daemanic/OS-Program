#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(void) {
  pid_t mypid = getpid();
  pid_t myppid = getppid();

  time_t currenttime = time(NULL);
  struct tm *time_info = localtime(&currenttime);

  printf("~ process information ~\n");
  printf("process id (pid): %d\n", mypid);
  printf("parent process id (ppid): %d\n", myppid);
  printf("current time: %s", asctime(time_info));
  printf("executable path: /proc/self/exe\n");

  return 0;
}

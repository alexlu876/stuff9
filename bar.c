#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){  
    printf("Oh no! SIGINT is attacking! Run away!!\n");
    int fd;
    fd = open("foo.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
    write(fd, "SIGINT has ended the process!", 256);
    close(fd);
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("You wanted a PID? Here: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(17){
    printf("hi, im: %d\n", getpid());
    sleep(1);
  }
  return 0;
}


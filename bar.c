#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  while(17){
    printf("hi, im: %d\n", getpid());
    sleep(1);
  }
  return 0;
}


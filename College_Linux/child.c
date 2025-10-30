#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void) {
 int p;
 p=fork();
 if(p==0) {
  printf("%d\n",getpid());
  printf("%d\n",getppid());
 }
 return 0;
}

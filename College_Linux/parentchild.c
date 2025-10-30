#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void) {
 int p,i=5;
 p=fork();
 if(p==0) {
  printf("Child process %d\n",++i);
 }
 if(p>0)
  printf("Parent Process %d\n",i);
 //else
  //printf("Error\n");
 return 0;
}

#include<stdio.h>
#include<unistd.h>
int main(void) {
 fork();
 fork();
 fork();
 printf("Hello from Child PID: %d, Parent PID: %d\n", getpid(), getppid());
 sleep(1);
 return 0;
}

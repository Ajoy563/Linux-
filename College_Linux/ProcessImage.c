#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
 printf("The PID is: %d\n", getpid());
 printf("This Process will now replaced by 'ls'\n");

 execl("/bin/date", "date", (char *)NULL);
 
 printf("\nThe PID is: %d\n", getpid());

 perror("execl Failed!!");
 return 0;
}  

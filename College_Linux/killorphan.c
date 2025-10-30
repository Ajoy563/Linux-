#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent: My PID is %d. Creating child...\n", getpid());
        sleep(2); 
        printf("Parent: Terminating myself with SIGKILL.\n");
        kill(getpid(), SIGKILL); 
    }
    else {
        printf("Child: My PID is %d. My initial parent PID is %d\n", getpid(), getppid());
        sleep(5);
        printf("Child: After parent dies, my new parent PID is %d\n", getppid());
        printf("Child: I am now an orphan adopted by init/systemd.\n");
    }
    return 0;
}


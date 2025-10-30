#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID: %d) is running.\n", getpid());
        printf("Child process is exiting.\n");
        exit(0);
    } 
    else {
        printf("Parent process (PID: %d) is sleeping.\n", getpid());
        sleep(10);
        printf("Parent process is awake now.\n");
    }

    return 0;
}


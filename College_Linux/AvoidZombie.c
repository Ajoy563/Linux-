#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(2);
        printf("Child process is exiting.\n");
        exit(0);
    } 
    else {
        int status;
        wait(&status);
        printf("Parent process (PID: %d) collected child. No zombie created.\n", getpid());
    }

    return 0;
}


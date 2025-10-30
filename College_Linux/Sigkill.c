#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork(); 

    if (pid == 0) {
        printf("Child process started. PID = %d\n", getpid());
        while (1) {
            printf("Child is still running...\n");
            sleep(1);
        }
    }
    else {
        printf("Parent process. Child PID = %d\n", pid);
        sleep(3); 
        printf("Parent is sending SIGKILL to child...\n");

        if (kill(pid, SIGKILL) == 0) {
            printf("Child process %d has been killed.\n", pid);
        } else {
            perror("Failed to kill child process");
        }
    }

    return 0;
}


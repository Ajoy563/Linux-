#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child Proces: PID = %d (Parent PID = %d)\n", getpid(), getppid());
	printf("Child Process executing ....\n");
	sleep(2);
	printf("Child Process Finished execution\n");
    }
    else {
	printf("Parent Process: PID = %d (Child PID = %d)\n", getpid(), pid);
	printf("Parent Process is not waiting for the Child Process\n");
    }
    return 0;
}


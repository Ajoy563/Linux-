#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        execl("/bin/date", "date", (char *)NULL);
        perror("execl failed"); // Only runs if execl fails
    } else {
        // Parent process
        wait(NULL); // Wait for child to finish
        printf("Child finished. Now executing more code in parent.\n");
    }

    return 0;
}


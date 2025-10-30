#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void my_handler(int signum) {
    printf("\nYou pressed Ctrl+C, but the program will not quit now.\n");
}
int main() {
    signal(SIGINT, my_handler);

    printf("Try pressing Ctrl+C now. It won't quit for 10 seconds.\n");

    sleep(10);  
    printf("\nNow restoring default Ctrl+C behavior.\n");

        signal(SIGINT, SIG_DFL);

    while (1) {
        printf("Program running. Press Ctrl+C to quit.\n");
        sleep(2);
    }

    return 0;
}


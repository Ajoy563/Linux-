#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    int key = 1234; 
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    if (semid == -1) {
        printf("Failed to create semaphore.\n");
        return 1;
    }

    semctl(semid, 0, SETVAL, 1); 
    printf("Binary semaphore created.\n");

    semctl(semid, 0, IPC_RMID, 0);
    printf("Binary semaphore released(deleted).\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    int key = 5678; 
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    if (semid == -1) {
        printf("Failed to create semaphore.\n");
        return 1;
    }

    semctl(semid, 0, SETVAL, 5); 
    printf("Counting semaphore created.\n");

    semctl(semid, 0, IPC_RMID, 0);
    printf("Counting semaphore released(deleted).\n");

    return 0;
}

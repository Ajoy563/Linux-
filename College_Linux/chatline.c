#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 5000
#define BUF_SIZE 256

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    fd_set readfds;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Connected to chat. Type your messages:\n");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        FD_SET(STDIN_FILENO, &readfds);

        int max_fd = (sock > STDIN_FILENO ? sock : STDIN_FILENO);

        select(max_fd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            fgets(buffer, BUF_SIZE, stdin);
            write(sock, buffer, strlen(buffer));
        }

        if (FD_ISSET(sock, &readfds)) {
            valread = read(sock, buffer, BUF_SIZE);
            if (valread <= 0) {
                printf("Disconnected from server.\n");
                break;
            }
            buffer[valread] = '\0';
            printf("Friend: %s", buffer);
        }
    }

    close(sock);
    return 0;
}

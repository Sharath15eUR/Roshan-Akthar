#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_BUFFER_SIZE 1024

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[MAX_BUFFER_SIZE] = "Hello from UDP Client!";

    // Create UDP socket
    if ((clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Send message to server
    ssize_t sentLen = sendto(clientSocket, buffer, strlen(buffer), 0, (const struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (sentLen < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server: %s\n", buffer);

    // Receive response from server
    ssize_t recvLen = recvfrom(clientSocket, buffer, MAX_BUFFER_SIZE, 0, NULL, NULL);
    if (recvLen < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    buffer[recvLen] = '\0'; // Null-terminate the received message
    printf("Response from server: %s\n", buffer);

    close(clientSocket);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create UDP socket
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Bind the socket to port 8080
    if (bind(serverSocket, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", PORT);

    // Receive message from client
    ssize_t recvLen = recvfrom(serverSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (recvLen < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Message from client: %s\n", buffer);

    // Send response back to client
    const char *response = "Hello from UDP Server!";
    ssize_t sentLen = sendto(serverSocket, response, strlen(response), 0, (const struct sockaddr *)&clientAddr, clientAddrLen);
    if (sentLen < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    printf("Response sent to client: %s\n", response);

    close(serverSocket);

    return 0;
}

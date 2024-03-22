#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // sending connection request
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // sending data
    char msg1[] = "Hello from Client!";
    ssize_t bytesSent = send(clientSocket, msg1, strlen(msg1), 0);
    if (bytesSent < 0)
    {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // receiving data
    char msg2[1024] = {0};
    ssize_t bytesReceived = recv(clientSocket, msg2, sizeof(msg2), 0);
    if (bytesReceived < 0)
    {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    else if (bytesReceived == 0)
    {
        printf("Server disconnected\n");
    }
    else
    {
        printf("Message from Server: %s\n", msg2);
    }

    close(clientSocket);

    return 0;
}


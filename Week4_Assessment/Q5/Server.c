#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0; // Not a palindrome
    }
    return 1; // Palindrome
}

int main() {
    int serverSocket;
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Failed ");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if ((bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) < 0) {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    }

    if ((listen(serverSocket, 5)) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }

    int clientSocket = accept(serverSocket, NULL, NULL);

    // receiving data
    char msg1[1024] = {0};
    ssize_t bytesReceived = recv(clientSocket, msg1, sizeof(msg1), 0);
    if (bytesReceived < 0) {
        perror("Receive Failed");
        exit(EXIT_FAILURE);
    } else if (bytesReceived == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Message from Client: %s\n", msg1);
        
        // Check if the received string is a palindrome
        if (isPalindrome(msg1))
            send(clientSocket, "Palindrome", strlen("Palindrome"), 0);
        else
            send(clientSocket, "Not a Palindrome", strlen("Not a Palindrome"), 0);
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}

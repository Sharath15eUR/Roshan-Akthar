#include <stdio.h>
#include <pthread.h>

void *printHello(void *arg) {
    printf("Hello ");
    pthread_exit(NULL);
}

void *printWorld(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t helloThread, worldThread;
    int status;

    status = pthread_create(&helloThread, NULL, printHello, NULL);
    if (status) {
        fprintf(stderr, "Error creating thread for Hello\n");
        return 1;
    }

    pthread_join(helloThread, NULL);

    status = pthread_create(&worldThread, NULL, printWorld, NULL);
    if (status) {
        fprintf(stderr, "Error creating thread for World\n");
        return 1;
    }

    pthread_join(worldThread, NULL);

    return 0;
}

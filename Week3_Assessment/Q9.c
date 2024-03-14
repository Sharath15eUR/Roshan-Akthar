#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
#define ITERATIONS 1000000

int counter = 0;
pthread_mutex_t mutex;

void* thread_function(void* arg)
{
    for (int i = 0; i < ITERATIONS; ++i)
    {
        pthread_mutex_lock(&mutex); 
        counter++; 
        pthread_mutex_unlock(&mutex); 
    }
    return NULL;
}

int main() 
{
    pthread_t threads[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) 
    {
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) 
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("Final counter value: %d\n", counter);

    return 0;
}

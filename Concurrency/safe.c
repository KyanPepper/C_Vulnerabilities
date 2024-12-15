#include <pthread.h>
#include <stdio.h>

int shared_variable = 0;  // Shared global variable
pthread_mutex_t lock;     // Declare a mutex

void* increment(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);   // Acquire the mutex
        shared_variable++;           // Critical section
        pthread_mutex_unlock(&lock); // Release the mutex
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&lock);   // Acquire the mutex
        shared_variable--;           // Critical section
        pthread_mutex_unlock(&lock); // Release the mutex
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    // Print the result of the shared variable
    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}

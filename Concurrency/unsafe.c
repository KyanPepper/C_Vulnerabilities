#include <pthread.h>
#include <stdio.h>

int shared_variable = 0;  // Shared global variable

void* increment(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        shared_variable++;  // Increment shared variable
    }
    return NULL;
}



void* decrement(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        shared_variable--;  // Decrement shared variable
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the result of the shared variable
    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}

/**
 * q3.cpp
 * Purpose: This is a multithreaded program in C or C++ that explores the synchronization challenge.
 * @author Zhou Liu
 * @version 1.0
 * 5/24/23
 */
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 3
#define MAX_TURNS 2

int allowed_ID = 1;
int threadTurns[NUM_THREADS] = {0};

pthread_mutex_t mutex;
pthread_cond_t cond;

void* threadFunction(void* threadID)
{
    int id = *((int*)threadID);

    for (int i = 0; i < MAX_TURNS; ++i) {
        pthread_mutex_lock(&mutex);

        // Wait until it's this thread's turn
        while (allowed_ID != id) {
            std::cout << "Not thread " << id << "'s turn" << std::endl;
            pthread_cond_wait(&cond, &mutex);
        }

        // Print the turn message
        std::cout << "Thread " << id << "'s turn!" << std::endl;

        // Increment allowed_ID and reset if it reaches 4
        allowed_ID = (allowed_ID % NUM_THREADS) + 1;

        // Notify other threads
        pthread_cond_broadcast(&cond);

        // Update the number of turns for this thread
        ++threadTurns[id - 1];

        pthread_mutex_unlock(&mutex);

        // Terminate the thread if it has printed the message twice
        if (threadTurns[id - 1] == MAX_TURNS) {
            break;
        }
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS] = {1, 2, 3};

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, threadFunction, (void*)&threadIDs[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

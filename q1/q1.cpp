/*
 * q1.cpp
 * Purpose: This program calculates various statistical values for a list of numbers.
 * This program will be passed a series of numbers on the command line and will then create three separate
 * worker threads. One thread will determine the average of the numbers, the second will determine the maximum value,
 * and the third will determine the minimum value.
 * @author Zhou Liu
 * @version 1.0
 * 5/24/23
 */
#include <iostream>
#include <pthread.h>

#define MAX_ELEMENTS 50

int arr[MAX_ELEMENTS];
int n;
int sum = 0;
int min_val, max_val;
int average = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *readArray(void *arg)
{
    pthread_mutex_lock(&mutex);

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *findMinimum(void *arg)
{
    pthread_mutex_lock(&mutex);

    min_val = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (min_val > arr[i])
        {
            min_val = arr[i];
        }
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *findMaximum(void *arg)
{
    pthread_mutex_lock(&mutex);

    max_val = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max_val < arr[i])
        {
            max_val = arr[i];
        }
    }

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *calculateAverage(void *arg)
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    average = (float)sum / n;

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, NULL, readArray, NULL);
    pthread_create(&t2, NULL, findMinimum, NULL);
    pthread_create(&t3, NULL, findMaximum, NULL);
    pthread_create(&t4, NULL, calculateAverage, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&mutex);

    std::cout << "Average = " << average << std::endl;
    std::cout << "Minimum value = " << min_val << std::endl;
    std::cout << "Maximum value = " << max_val << std::endl;

    return 0;
}

/**
 * q2.cpp
 * Purpose: This is a multithreaded sorting program, A list of integers is divided into two smaller lists of equal size.
 * Two separate threads sort each sublist using a sorting algorithm of your choice.
 * The two sublists are then merged by a third thread—a merging thread —
 * which merges the two sublists into a single sorted list.
 *
 * @author Zhou Liu
 * @version 1.0
 * 5/24/23
 */
#include <iostream>
#include <pthread.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];          // Array to store user input
int sortedArr[MAX_SIZE];    // Global array for storing the sorted list

// Structure for passing arguments to the thread
struct ThreadArgs {
    int* array;
    int start;
    int end;
};

// Merge function to merge two sorted subarrays
void merge(int* array, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j])
            array[k++] = leftArray[i++];
        else
            array[k++] = rightArray[j++];
    }

    while (i < leftSize)
        array[k++] = leftArray[i++];
    while (j < rightSize)
        array[k++] = rightArray[j++];

    delete[] leftArray;
    delete[] rightArray;
}

// Recursive merge sort function
void mergeSort(int* array, int start, int end)
{
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}

// Thread function for merge sort
void* mergeSortThread(void* arg)
{
    ThreadArgs* args = static_cast<ThreadArgs*>(arg);
    mergeSort(args->array, args->start, args->end);
    return NULL;
}

int main()
{
    int n;  // Number of elements

    std::cout << "Enter the number of elements to be sorted: ";
    std::cin >> n;

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    pthread_t sortThread;
    ThreadArgs threadArgs;

    threadArgs.array = arr;
    threadArgs.start = 0;
    threadArgs.end = n - 1;

    // Create the sorting thread
    pthread_create(&sortThread, NULL, mergeSortThread, &threadArgs);

    // Wait for the sorting thread to finish
    pthread_join(sortThread, NULL);

    std::cout << "num: " << n << ", half size = " << n/2 << std::endl;
    // Print the sorted list
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

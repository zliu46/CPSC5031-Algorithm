//Zhou Liu
//Purpose: this program will count the numbers of inversion in a given integer array A[i ... j].
//Inversions happen when the numbers in the array are out of order. (A[i] > A [j], i < j).
//@version 1.0
//4/21/23
#include <iostream>
using namespace std;
int countInversionsRec(int*, int*, int, int);
int mergeCount(int *, int*, int, int, int);
void testInversion1();
void testInversion2();
void testInversion3();
//This function will sort the array and return the number of inversions.
//IN: integer array, the size of array.
//OUT: numbers of inversions.
int countInversions(int * A, int n) {
    int * temp = new int(n);//Create a temp array.
    //Call a recursive function to get the number of inversions.
    return countInversionsRec(A, temp, 0, n - 1);
}
//This is the helper function to sort the array and return the number of inversions.
//IN: input array, temp array, left index of array, right index of array.
//OUT: the number of inversions.
int countInversionsRec(int * arr, int * temp, int left, int right) {
    int mid, count = 0;//Initialize the mid-index and the number of inversions.
    if (left < right) {
        mid = (left + right) / 2;//Divide the array into half.
        count += countInversionsRec(arr, temp, left, mid);//Call the recursive function for left part.
        count += countInversionsRec(arr, temp, mid + 1, right);//Call the recursive function for right part.
        count += mergeCount(arr, temp, left, mid + 1, right);//Merge left side and right side.
    }
    return count;//Return the number of inversions.
}
//This function will merge the left side of the array and the right side of the array.
//IN: integer array, temp array, left index, mid index, right index.
//OUT: the number of inversion.
int mergeCount(int * arr, int * temp, int left, int mid, int right) {
    int count = 0;//Initialize the number of inversions.
    int i, k, j;//To hold the indexes.
    i = left;
    k = mid;
    j = left;
    //Using while loop to copy the elements to the temp array.
    while (i <= mid - 1 && k <= right) {
        if (arr[i] <= arr[k]) {
            temp[j++] = arr[i++];
        }
        else {
            temp[j++] = arr[k++];
            count += (mid - i);
        }
    }
    //Copying the left side of array to temp array.
    while(i <= mid - 1) {
        temp[j++] = arr[i++];
    }
    //Copying the right side of array to temp array.
    while(k <= right) {
        temp[j++] = arr[k++];
    }
    //Copying the elements in the merged array back to the input array.
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;//Return the number of inversions.
}
//This is the main function that tests the countInversions function.
int main() {
    //Call the test function.
    testInversion1();
    //Call the test function.
    testInversion2();
    //Call the test function.
    testInversion3();
    return 0;
}
//Test function.
void testInversion1(){
    //Create an array.
    int arr [] = {10, 5, 20, 3, 8};
    //Get the size of array.
    int n = sizeof (arr) / sizeof (arr[0]);
    //Get the number of inversions.
    int count = countInversions(arr, n);
    //Prints out the result.
    cout << "Number of inversions: " << count << endl;
};
//Test function.
void testInversion2(){
    //Create an array.
    int arr [] = {8, 3,  4, 6};
    //Get the size of array.
    int n = sizeof (arr) / sizeof (arr[0]);
    //Get the number of inversions.
    int count = countInversions(arr, n);
    //Prints out the result.
    cout << "Number of inversions: " << count << endl;
};
//Test function.
void testInversion3(){
    //Create an array.
    int arr [] = {8, 1, 2};
    //Get the size of array.
    int n = sizeof (arr) / sizeof (arr[0]);
    //Get the number of inversions.
    int count = countInversions(arr, n);
    //Prints out the result.
    cout << "Number of inversions: " << count << endl;
};


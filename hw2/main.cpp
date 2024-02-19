#include <iostream>
using namespace std;
int computePoly(int *, int);
int main() {
    int * array = new int [10];
    computePoly(array, 5);


    return 0;
}
int computePoly(int * array, int n) {
    int sum = 0;
    for (int i = n; i >= 0; i--) {
        int power = 1;
        for (int j = 1; i <= i; j++) {
            sum += array[i] * power;
        }
    }
    return sum;
}
int computePolyLinear(int * array, int n) {
    int p = array[0];
    int power = 1;
    for (int i = 1; i <= n; i++) {
        p += p + array[i] * power;
    }
    return p;
}
int computeSubstrings(string * array) {
    int count = 0;
    int n = array->length();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (array[i] == "A" && array[j] == "B" )
                count++;
    }
    return count;
}

int computeSubstrings(string * array) {
    int count = 0;
    int total = 0;
    int n = array->length();
    for (int i = 0; i < n; i++) {
        if (array[i] == "A") {
            count++;
        }
        else if (array[i] == "B") {
            total += count;
            count = 0;
        }
    }
    return total;
}
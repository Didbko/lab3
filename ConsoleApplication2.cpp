#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main() {
    for (int i = 0; i < 1099999; i++) {
        int arr[100];
        for (int i = 0; i < 100; i++) {
            arr[i] = rand() % 100 + 1;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        bubbleSort(arr, n);
    }
    cout << "OK";
    return 0;
}
#include <iostream>
#include<chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

void fill_random(int array[], int length, int max);

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void fill_random(int array[], int length, int max)
{
    for (int i = 0; i < length; i++)
        array[i] = (rand() % max) + 1;
}

int main() {
    auto start = high_resolution_clock::now();
    srand(time(NULL));
    for (int i = 0; i < 2000000; i++) {
        int a[100];
        fill_random(a, 50, 100000);
        int size_a = sizeof(a) / sizeof(a[0]);
        selectionSort(a, size_a);
        //search(a, size_a, 666);
        for (int j = 0; j < 100; j ++) {
            if (j % 2 == 0) {
                a[j] = round(a[j] + 0.8);
            }
        }
        bubbleSort(a, size_a);
    }
    
    cout << "Array is sorted!";
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;
}
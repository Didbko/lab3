#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}


int main() {
    srand(time(NULL));
    for (int i = 0; i < 1000000; i++) {
        int a[100];
        for (int j = 0; j < 100; j++) {
            a[j] = rand() % 1000 + 1;
        }
        int size_a = sizeof(a) / sizeof(a[0]);
        for (int j = 0; j < 100; j++) {
            insertionSort(a, size_a);
        }
        search(a, size_a, 666);
    }
    cout << "Done" << endl;
    return 0;
}
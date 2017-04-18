#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];                             //哨兵
    while (low < high) {
        while (low < high && a[high] >= pivot) --high;  //high->low 小的扔到low的位置
        swap(&a[low], &a[high]);
        while (low < high && a[low] <= pivot) ++low;   //low->high 大的扔到high的位置
        swap(&a[low], &a[high]);
    }
    return low;
}

void quicksort(int unsorted[], int low, int high) {
    if (low < high) {
        int piv = partition(unsorted, low, high);
        quicksort(unsorted, low, piv - 1);
        quicksort(unsorted, piv + 1, high);
    }
}

int main() {
    int unsorted[10] = {3, 2, 3, 54, 65, 1, 8, 5, 10, 2};
    int length = sizeof(unsorted) / sizeof(int);
    quicksort(unsorted, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        cout << unsorted[i] << " ";
    }
    return 0;
}
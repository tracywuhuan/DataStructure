#include <iostream>

using namespace std;
// stable
void insert(int unsorted[], int num) {
    int temp;
    for (int i = 0; i < num - 1; ++i) {
        temp = unsorted[i + 1];
        for (int j = i; j >= 0; --j) {
            if (temp < unsorted[j]) {
                unsorted[j + 1] = unsorted[j];
                unsorted[j] = temp;
            }
        }
    }
}

int main() {
    int unsorted[10] = {3, 2, 3, 54, 65, 1, 8, 5, 10, 2};
    int length = sizeof(unsorted) / sizeof(int);
    insert(unsorted, length);
    for (int i = 0; i < length; ++i) {
        cout << unsorted[i] << " ";
    }
    return 0;
}
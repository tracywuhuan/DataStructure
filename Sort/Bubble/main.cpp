#include <iostream>

using namespace std;

void bubble(int unsorted[], int num) {
    for (int j = num; j > 0; --j) {
        for (int i = 0; i < j - 1; ++i) {
            if (unsorted[i] > unsorted[i + 1]) {
                int temp = unsorted[i + 1];
                unsorted[i + 1] = unsorted[i];
                unsorted[i] = temp;
            }
        }
    }
}

int main() {
    int unsorted[10] = {3, 2, 3, 54, 65, 1, 8, 5, 10, 2};
    int length = sizeof(unsorted) / sizeof(int);
    bubble(unsorted, length);
    for (int i = 0; i < length; ++i) {
        cout << unsorted[i] << " ";
    }
    return 0;
}
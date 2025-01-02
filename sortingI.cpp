#include <iostream>
#include <vector>
using namespace std;

// ########## TERMS ###############
// - Stable : Relative order of terms with equal keys remains same
// - In-place : Doesn't requires extra space

// BUBBLE SORT || (Inplace, stable, simple) (Time: O(N^2), Space: O(1))
void bubbleSort(vector<int> &arr, bool ascending=true) {
    int N = arr.size();
    int n = N;
    for (int i = 0; i < N - 1; i++) {
        bool swapped = false;
        for (int j = 1; j < n; j++) {
            if (ascending && arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                swapped = true;
            } else if (!ascending && arr[j-1] < arr[j]) {
                swap(arr[j-1], arr[j]);
                swapped = true;
            }
        }
        if (!swapped) { // If no swaps occur, array is sorted
            break;
        }
        n--; // Because the sorted elements get pused to one side
    }
}

// INSERTION SORT || (Inplace, stable) (Time: O(N^2), Space: O(1)) : Swaps < Bubble sort
void insertionSort(vector<int> &arr, bool ascending=true) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        if (ascending) {
            for (; j >= 0 && arr[j] > temp; j--) {
                arr[j + 1] = arr[j];
            }
        } else {
            for (; j >= 0 && arr[j] < temp; j--) {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = temp;
    }
}

// SELECTION SORT || (Inplace, Un-stable) (Time: O(N^2), Space: O(1)) : Swaps O(N)
// Could be used in places where writing to memory is more expensive, because it performs less writes than insertion sort.
void selectionSort(vector<int> &arr, bool ascending=true) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int idx = i;
        if (ascending) {
            for (int j = i+1; j < n; j++) {
                if (arr[idx] > arr[j]) { // Find minimum for ascending
                    idx = j;
                }
            }
        } else {
            for (int j = i+1; j < n; j++) {
                if (arr[idx] < arr[j]) { // Find maximum for descending
                    idx = j;
                }
            }
        }
        swap(arr[idx], arr[i]); // Swap with the ith element
    }
}

void printArr(vector<int> &arr) {
    for (auto& a : arr) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {
    vector<int> partialSorted{1,2,3,6,3,5,4};
    vector<int> reverseSorted{8,7,6,5,4,3,2,1};
    vector<int> sorted{1,2,3,3,4,5,6,7};

    printArr(partialSorted);
    selectionSort(partialSorted, false);
    cout << "RES: ";
    printArr(partialSorted);


    return 0;
}
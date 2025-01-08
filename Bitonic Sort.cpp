// Sorts by recursively creating bitonic sequences.
// Time Complexity: O(log² n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// Function to compare and swap elements in the required order
void bitonicCompare(vector<int>& arr, int low, int count, bool ascending) {
    for (int i = 0; i < count / 2; i++) {
        if (ascending == (arr[low + i] > arr[low + i + count / 2])) {
            swap(arr[low + i], arr[low + i + count / 2]);
        }
    }
}

// Function to recursively generate and sort the bitonic sequence
void bitonicSort(vector<int>& arr, int low, int count, bool ascending) {
    if (count <= 1)
        return;

    int mid = count / 2;

    // Sort the first half in ascending order
    bitonicSort(arr, low, mid, true);

    // Sort the second half in descending order
    bitonicSort(arr, low + mid, mid, false);

    // Merge the two halves into a single sorted sequence
    bitonicCompare(arr, low, count, ascending);
}

// Driver function to start the Bitonic Sort
void bitonicSort(vector<int>& arr) {
    bitonicSort(arr, 0, arr.size(), true);
}

int main() {
    vector<int> arr = {3, 7, 2, 8, 6, 4, 5, 1};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    bitonicSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

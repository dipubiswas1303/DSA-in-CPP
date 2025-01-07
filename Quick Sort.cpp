// Divides the array based on a pivot, then sorts each partition.
// Time Complexity: O(n log n) (average), O(n²) (worst case)
// Space Complexity: O(log n) (in-place)

#include <iostream>
#include <vector>
using namespace std;

// Partition function to place pivot element in the correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap elements smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in its correct position
    return i + 1; // Return the partition index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

// Generalization of insertion sort with gaps between compared elements.
// Time Complexity: O(n log² n) (depends on gap sequence)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Shell Sort function
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift earlier gap-sorted elements up until the correct location is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the temp element in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

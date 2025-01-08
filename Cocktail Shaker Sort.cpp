// A bidirectional bubble sort.
// Time Complexity: O(n²)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Cocktail Shaker Sort function
void cocktailShakerSort(vector<int>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        // Reset swapped to false to check if any swaps happen
        swapped = false;

        // Forward pass: move the largest element to the end
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;

        // Reset swapped for the next pass
        swapped = false;

        // Decrement the end point as the last element is already sorted
        end--;

        // Backward pass: move the smallest element to the start
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Increment the start point as the first element is already sorted
        start++;
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8, 0, 2};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    cocktailShakerSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

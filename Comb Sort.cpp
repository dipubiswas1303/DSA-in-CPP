// Improves bubble sort by comparing elements at a gap larger than 1.
// Time Complexity: O(n log n) (average)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to get the next gap
int getNextGap(int gap) {
    // Shrink gap by a shrink factor of 1.3
    gap = (gap * 10) / 13;
    return (gap < 1) ? 1 : gap;
}

// Comb Sort function
void combSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;

    // Continue until the gap is 1 and no swaps are performed
    while (gap != 1 || swapped) {
        // Calculate the next gap
        gap = getNextGap(gap);

        // Reset swapped to false
        swapped = false;

        // Compare and swap elements at a distance of `gap`
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    vector<int> arr = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    combSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

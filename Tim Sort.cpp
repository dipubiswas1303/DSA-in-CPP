// Hybrid of merge and insertion sort (used in Python and Java).
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the minimum size of a run
const int RUN = 32;

// Function to perform insertion sort on a subarray
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Merge function to merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    vector<int> leftArr(len1), rightArr(len2);

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Tim Sort function
void timSort(vector<int>& arr) {
    int n = arr.size();

    // Sort individual subarrays of size RUN using insertion sort
    for (int i = 0; i < n; i += RUN) {
        insertionSort(arr, i, min(i + RUN - 1, n - 1));
    }

    // Merge sorted runs using a bottom-up approach
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
    vector<int> arr = {5, 21, 7, 23, 19, 10, 1, 3, 13, 8};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    timSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

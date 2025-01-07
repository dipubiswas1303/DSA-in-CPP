// Processes digits of numbers from least to most significant using counting sort as a subroutine.
// Time Complexity: O(nk) (where k is the number of digits)
// Space Complexity: O(n + k)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform counting sort on the basis of a specific digit
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array to store sorted values
    vector<int> count(10, 0); // Count array to store digit frequencies

    // Count occurrences of digits in the current place (exp)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Update count array to store actual positions of digits
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing numbers in their correct positions
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted numbers back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum number to determine the number of digits
    int maxVal = *max_element(arr.begin(), arr.end());

    // Perform counting sort for each digit (starting from the least significant)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

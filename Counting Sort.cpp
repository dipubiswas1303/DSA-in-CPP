// Counts occurrences of each element and uses this count to place them in sorted order.
// Time Complexity: O(n + k) (where k is the range of input values)
// Space Complexity: O(n + k)

#include <iostream>
#include <vector>
using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum and minimum values in the array
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Create a count array and initialize it to 0
    vector<int> count(range, 0);

    // Count the occurrences of each element
    for (int num : arr) {
        count[num - minVal]++;
    }

    // Overwrite the original array with sorted values
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

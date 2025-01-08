// Randomly shuffles the array until it is sorted.
// Time Complexity: O((n-1)!)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to check if the array is sorted
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// Bogo Sort function
void bogoSort(vector<int>& arr) {
    // Continue shuffling until the array is sorted
    while (!isSorted(arr)) {
        random_shuffle(arr.begin(), arr.end());
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random_shuffle

    vector<int> arr = {3, 2, 5, 1, 4};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    bogoSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to check if the array is sorted
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

// Bogo Sort function
void bogoSort(vector<int>& arr) {
    // Continue shuffling until the array is sorted
    while (!isSorted(arr)) {
        random_shuffle(arr.begin(), arr.end());
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random_shuffle

    vector<int> arr = {3, 2, 5, 1, 4};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    bogoSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

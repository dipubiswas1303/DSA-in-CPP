// Distributes elements into buckets, sorts each bucket, and concatenates them.
// Time Complexity: O(n + k) (average case)
// Space Complexity: O(n + k)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bucket Sort function
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in the range [0, n-1]
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all sorted buckets back into the array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};

    cout << "Original array: ";
    for (float val : arr) {
        cout << val << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (float val : arr) {
        cout << val << " ";
    }
    return 0;
}

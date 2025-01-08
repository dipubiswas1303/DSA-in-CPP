// Distributes elements into pigeonholes based on their key.
// Time Complexity: O(n + k)
// Space Complexity: O(n + k)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Pigeonhole Sort function
void pigeonholeSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the range of the elements
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    // Create pigeonholes
    vector<vector<int>> holes(range);

    // Place each element in its corresponding hole
    for (int num : arr) {
        holes[num - minVal].push_back(num);
    }

    // Gather elements from pigeonholes back into the array
    int index = 0;
    for (const auto& hole : holes) {
        for (int num : hole) {
            arr[index++] = num;
        }
    }
}

int main() {
    vector<int> arr = {8, 3, 2, 7, 4, 6, 8, 5};

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    pigeonholeSort(arr);

    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    return 0;
}

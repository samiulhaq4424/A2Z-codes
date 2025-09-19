/*
  link: https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    // Store the first element temporarily
    int temp = arr[0];

    // Shift all elements one position to the left
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }

    // Place the first element at the last position
    arr[n - 1] = temp;

    return arr;
}

/*
📌 Problem:
-----------
Rotate the array to the left by 1 position.

📌 Example:
-----------
Input:  arr = [1,2,3,4,5], n = 5
Output: [2,3,4,5,1]

📌 Approach:
------------
- Store the first element in a temporary variable.
- Shift all remaining elements one step to the left.
- Assign the stored first element to the last index.

📌 Complexity:
---------------
Time Complexity (TC): O(n) → single pass through array
Space Complexity (SC): O(1) → in-place rotation, no extra space
*/

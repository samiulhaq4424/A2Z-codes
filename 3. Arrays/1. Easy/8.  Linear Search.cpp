/*
    https://www.naukri.com/code360/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/


#include <bits/stdc++.h> 
using namespace std;

int linearSearch(int n, int num, vector<int> &arr) {
    // Traverse the array linearly
    for (int i = 0; i < n; i++) {
        // If element matches, return its index
        if (arr[i] == num)
            return i;
    }
    // If not found, return -1
    return -1;
}

/*
📌 Problem:
------------
Find the index of the given element `num` in the array.
If the element is not present, return -1.

📌 Example:
------------
Input:  arr = [4, 2, 7, 1, 9], num = 7
Output: 2   (since arr[2] = 7)

📌 Complexity:
---------------
Time Complexity (TC): O(n)
    - In worst case, we may need to check all n elements
Space Complexity (SC): O(1)
    - No extra space used, just comparisons
*/

/*
    link: 
    https://leetcode.com/problems/rotate-array/description/
*/

#include <bits/stdc++.h> 
using namespace std;

/*
Time Complexity (TC): O(n) 
    - Three reversals, each O(n) at most → O(n) overall
Space Complexity (SC): O(1) 
    - In-place rotation, no extra memory used
*/

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k % n;  // handle case where k >= n

        // Step 1: Reverse the whole array
        reverse(a.begin(), a.end());

        // Step 2: Reverse the first k elements
        reverse(a.begin(), a.begin() + k);

        // Step 3: Reverse the remaining n-k elements
        reverse(a.begin() + k, a.end());
    }
};

/*
📌 Example Walkthrough
-----------------------
Input:  a = [1, 2, 3, 4, 5, 6, 7], k = 3

1) reverse whole array   → [7, 6, 5, 4, 3, 2, 1]
2) reverse first k=3     → [5, 6, 7, 4, 3, 2, 1]
3) reverse last n-k=4    → [5, 6, 7, 1, 2, 3, 4]

Final Rotated Array = [5, 6, 7, 1, 2, 3, 4]
*/

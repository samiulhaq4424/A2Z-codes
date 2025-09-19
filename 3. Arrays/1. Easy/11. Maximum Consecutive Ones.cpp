/*
    https://leetcode.com/problems/max-consecutive-ones/description/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;       // Counter for current consecutive 1s
        int maxi = 0;      // Stores the maximum consecutive 1s found so far

        // Traverse the array
        for (auto it : nums) {
            if (it == 1) {                 // If current element is 1
                ++cnt;                     // Increment current consecutive count
                maxi = max(maxi, cnt);     // Update maximum if current streak is higher
            } 
            else {                         // If current element is 0
                cnt = 0;                    // Reset current consecutive count
            }
        }

        return maxi;   // Return the maximum consecutive 1s found
    }
};

/*
📌 Problem:
-----------
Given a binary array, find the maximum number of consecutive 1s in the array.

📌 Example:
-----------
Input:  [1,1,0,1,1,1]
Output: 3
Explanation: The longest consecutive 1s sequence is [1,1,1]

📌 Approach:
------------
- Use a counter `cnt` to track consecutive 1s.
- Update `maxi` whenever `cnt` exceeds previous maximum.
- Reset `cnt` to 0 when a 0 is encountered.

📌 Complexity:
---------------
Time Complexity (TC): O(n)
    - Single pass through the array
Space Complexity (SC): O(1)
    - Constant space, no extra data structures used
*/

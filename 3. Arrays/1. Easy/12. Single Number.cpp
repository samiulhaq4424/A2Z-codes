/*
  https://leetcode.com/problems/single-number/description/
*/

#include <bits/stdc++.h>
using namespace std;

// 🔹 Approach 1: Brute Force (Count occurrences)
int singleNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int cnt = 0;
        // Count occurrences of nums[i]
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == nums[i]) {
                ++cnt;
                if (cnt == 2) // stop early if found twice
                    break;
            }
        }
        if (cnt == 1) // nums[i] occurs only once
            return nums[i];
    }
    return 0; // dummy return
}
/*
📌 Problem:
-----------
Find the element that appears only once in an array where every other element appears twice.

📌 Complexity:
---------------
Time Complexity (TC): O(n^2) → Nested loop
Space Complexity (SC): O(1) → No extra space used
*/


// 🔹 Approach 2: XOR Method (Optimal)
int singleNumber(vector<int>& nums) {
    int ans = 0;

    // XOR of all elements
    // x ^ x = 0 and x ^ 0 = x
    for (auto it : nums) {
        ans ^= it;
    }

    return ans; // single number
}
/*
📌 Problem:
-----------
Same as above.

📌 Approach:
------------
- XOR all elements in the array.
- Pairs of identical elements cancel out because x ^ x = 0.
- Only the unique element remains.

📌 Complexity:
---------------
Time Complexity (TC): O(n) → Single pass
Space Complexity (SC): O(1) → In-place, constant space
*/

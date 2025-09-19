#include <bits/stdc++.h>
using namespace std;

/*
Problem:
--------
Given an array 'nums' and an integer 'k', find the length of the
longest contiguous subarray whose sum equals 'k'.

Notes:
------
- Array may contain positive, negative, and zero numbers.
- For positive-only arrays, we can optimize using sliding window (O(1) space).
- For arrays with negatives/zeros, use prefix sum + hashmap (O(n) space).

-------------------------------
1️⃣ Approach 1: General case (positive + negative + zero)
   - Use prefix sum + hashmap.
   - Store the **first occurrence** of each prefix sum.
   - For each index i:
       * sum = sum of nums[0..i]
       * If sum == k, update max length
       * If (sum - k) exists in map, a subarray ending at i sums to k
       * Update max length
   - TC: O(n), SC: O(n)
*/

int getLongestSubarray(vector<int>& nums, int k) {
    unordered_map<long,int> mp; // prefix sum -> first occurrence index
    long sum = 0;
    int maxi = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i]; // running sum

        // Case when subarray starts from index 0
        if(sum == k) {
            maxi = max(maxi, i + 1);
        }

        // Check if a subarray ending at i sums to k
        long rem = sum - k;
        if(mp.find(rem) != mp.end()) {
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        // Store first occurrence of this prefix sum
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxi;
}

/*
-------------------------------
2️⃣ Approach 2: Positive numbers only (Sliding Window)
   - Use two pointers (start, end) to maintain a window
   - Add nums[end] to sum
   - While sum > k, shrink window from start
   - If sum == k, update maximum length
   - TC: O(n), SC: O(1)
*/

int longestSubarrayPositive(vector<int>& nums, int k) {
    int n = nums.size();
    int start = 0, end = 0, sum = 0, maxi = 0;

    while(end < n) {
        sum += nums[end];  // expand window

        // shrink window from start if sum > k
        while(sum > k && start <= end) {
            sum -= nums[start];
            start++;
        }

        // if sum equals k, update maximum length
        if(sum == k) {
            maxi = max(maxi, end - start + 1);
        }

        ++end;
    }

    return maxi;
}

/*
Example:
--------
nums = [1, 2, 1, 1, 1, 1], k = 3

Approach 1 (general case):
- Works for negative numbers too
- Output: 3 (subarray [1,1,1])

Approach 2 (positive only):
- Optimized using sliding window
- Output: 3 (same subarray)

Key Points:
-----------
- For positive-only arrays, sliding window is faster and uses O(1) space
- For arrays with negatives or zeros, use prefix sum + hashmap
- Always store **first occurrence** of prefix sum to maximize length
*/

/*
Problem Link:
-------------
https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505

Problem:
--------
Given an array nums (can contain positive, negative, and zero) and an integer k,
find the length of the longest contiguous subarray whose sum equals k.

Example:
--------
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3.

Approach:
---------
- Use a prefix sum approach with a hashmap.
- Maintain a running sum while iterating through the array.
- For each sum, check if (sum - k) exists in the map:
    - If yes, a subarray ending at current index sums to k.
    - Update the maximum length if this subarray is longer.
- Store the **first occurrence** of each prefix sum in the map to get the longest subarray.

Time Complexity (TC): O(n)
- Single pass through the array.

Space Complexity (SC): O(n)
- Hashmap stores prefix sums and their first occurrences.

*/

#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
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

        // Store first occurrence of this prefix sum (V.IMP)
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxi; // length of longest subarray with sum k
}

// https://www.codingninjas.com/studio/problems/count-frequency-in-a-range_8365446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf



/*
Problem:
--------
Given an array 'nums' of length 'n' containing integers in range 1..x,
count the frequency of all elements from 1 to n. 
Return a frequency array 'ans' such that:
- ans[0] = frequency of 1
- ans[1] = frequency of 2
- ...
- ans[n-1] = frequency of n

Approach:
---------
1. Create a frequency array 'ans' of size n, initialized with 0.
2. Iterate through the input array 'nums':
   - Only consider numbers <= n (ignore numbers > n)
   - Increment the corresponding frequency:
       ans[nums[i]-1]++
     (-1 because index 0 represents number 1)
3. Return the 'ans' array.

Example:
--------
Input: n = 6, x = 9, nums = [1, 3, 1, 9, 2, 7]

Step-by-step:
- 1 → ans[0] += 1 → ans = [1,0,0,0,0,0]
- 3 → ans[2] += 1 → ans = [1,0,1,0,0,0]
- 1 → ans[0] += 1 → ans = [2,0,1,0,0,0]
- 9 → ignore (9 > 6)
- 2 → ans[1] += 1 → ans = [2,1,1,0,0,0]
- 7 → ignore (7 > 6)

Output: [2,1,1,0,0,0]

Time Complexity (TC):
--------------------
- O(n) → single pass through the array 'nums'

Space Complexity (SC):
---------------------
- O(n) → frequency array 'ans'
*/

#include <bits/stdc++.h> 
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> ans(n,0);  // frequency array
    for(int i=0; i<n; i++){
        if(nums[i] <= n) {   // only count numbers 1..n
            ans[nums[i] - 1]++; // map number to index
        }
    }
    return ans;
}

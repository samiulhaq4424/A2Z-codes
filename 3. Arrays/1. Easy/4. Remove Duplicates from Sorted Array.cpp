/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/


#include <bits/stdc++.h> 
using namespace std;

// ✅ Function: removeDuplicates
// Goal: Remove duplicates from sorted array (like LeetCode 26)
// and return the new length (unique elements only).
// NOTE: This version uses a set, so it also works if input is unsorted,
// but it has extra O(n log n) time + O(n) space.

int removeDuplicates(vector<int>& nums) {
    set<int> st;   // set stores unique elements in sorted order
    int cnt = 0;

    // Insert all elements into set → duplicates removed automatically
    for (auto it : nums) {
        st.insert(it);
    }
    
    int indx = 0;
    // Copy back unique elements from set into nums
    for (auto it : st) {
        nums[indx] = it;   // overwrite nums in place
        indx++;
    }

    // 'indx' now represents the count of unique elements
    return indx;
}




/* Optimal method
📌 Complexity Analysis:
---------------------------------
Time Complexity (TC): O(n)
    - We scan the array once (single loop through nums).
    - Each comparison and assignment is O(1).
    - Total: O(n), where n = nums.size().

Space Complexity (SC): O(1)
    - We only use a few variables (indx, i).
    - No extra data structures proportional to n.
    - Modifies nums in-place.
*/
int removeDuplicates(vector<int>& nums) {
    // Pointer (index) to track the last position of unique element
    int indx = 0;  

    // Traverse the array starting from the beginning
    for (int i = 0; i < nums.size(); i++) {
        // If we find a new unique element (different from last stored one)
        if (nums[indx] != nums[i]) {
            indx++;                // move pointer forward
            nums[indx] = nums[i];  // place the new unique element here
        }
    }

    // The array is now "compressed" in-place.
    // Unique elements are stored from nums[0] to nums[indx].
    // Since indx is 0-based, total count of unique elements = indx + 1.
    return indx + 1;
}




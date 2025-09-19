/*
    https://www.naukri.com/code360/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/


#include <bits/stdc++.h> 
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;       // pointers for array a and b
    vector<int> ans;        // result array (merged, unique)

    // Step 1: Merge both arrays while avoiding duplicates
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            // Push only if ans is empty or last element != current
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            ++i;
        }
        else if (b[j] < a[i]) {
            if (ans.empty() || ans.back() != b[j]) {
                ans.push_back(b[j]);
            }
            ++j;
        }
        else { // a[i] == b[j]
            if (ans.empty() || ans.back() != a[i]) {
                ans.push_back(a[i]);
            }
            ++i;
            ++j;  // skip duplicate from both arrays
        }
    }

    // Step 2: Append remaining elements from a
    while (i < n1) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        ++i;
    }

    // Step 3: Append remaining elements from b
    while (j < n2) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        ++j;
    }

    return ans; // merged sorted array without duplicates
}

/*
📌 Problem:
-----------
Merge two sorted arrays into a single sorted array
without duplicates.

📌 Example:
-----------
Input: a = [1,2,3,4,6], b = [2,3,5]
Output: [1,2,3,4,5,6]

📌 Approach:
------------
- Use two pointers i (for a) and j (for b)
- Compare a[i] and b[j]:
  - Push the smaller element if it’s not equal to the last element in ans
  - If equal, push once and increment both pointers
- After one array is exhausted, append remaining elements, skipping duplicates

📌 Complexity:
---------------
Time Complexity (TC): O(n1 + n2)
    - Each element is visited at most once
Space Complexity (SC): O(n1 + n2)
    - Extra array 'ans' to store merged unique elements
*/

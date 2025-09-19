/*
    https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
*/

#include <bits/stdc++.h>
using namespace std;


// 🔹 Approach 1: Using extra space (temp vector)
vector<int> moveZeros(int n, vector<int> a) {
    // Step 1: Collect all non-zero elements in a temporary vector
    vector<int> temp;
    for (auto it : a) {
        if (it != 0) {
            temp.push_back(it);
        }
    }

    // Step 2: Copy non-zero elements back to 'a' (from start)
    for (int i = 0; i < temp.size(); i++) {
        a[i] = temp[i];
    }

    // Step 3: Fill the rest with zeros
    for (int i = temp.size(); i < n; i++) {
        a[i] = 0;
    }

    return a;
}

/*
📌 Example:
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]

📌 Complexity:
- Time Complexity (TC): O(n)  
  → One loop to collect, one loop to copy, one loop to fill zeros
- Space Complexity (SC): O(n)  
  → Extra vector `temp` used to store non-zero elements
*/


// 🔹 Approach 2: Optimal (In-place, no extra space)
vector<int> moveZeros(int n, vector<int> a) {
    int indx = 0;  // pointer to place next non-zero element

    // Step 1: Shift all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[indx++] = a[i];
        }
    }

    // Step 2: Fill remaining positions with zeros
    for (int i = indx; i < n; i++) {
        a[i] = 0;
    }

    return a;
}

/*
📌 Complexity:
- Time Complexity (TC): O(n)  
  → Single pass for non-zeros + single pass for filling zeros
- Space Complexity (SC): O(1)  
  → In-place, no extra data structure
*/

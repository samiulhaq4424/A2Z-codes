/*
    https://www.naukri.com/code360/problems/missing-number_6680467
*/

#include <bits/stdc++.h>
using namespace std;

// 🔹 Approach 1: Brute Force (Check each number)
int missingNumber(vector<int>& a, int N) {
    // Loop through all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        bool found = false;
        // Check if current number exists in array
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == i) {
                found = true;
                break;
            }
        }
        // If not found, return as missing number
        if (!found)
            return i;
    }
    return -1; // just in case
}
/*
Time Complexity (TC): O(N^2) → Nested loop (i from 1 to N, j over array)
Space Complexity (SC): O(1) → No extra space
*/


// 🔹 Approach 2: Sum Formula
int missingNumber(vector<int>& a, int N) {
    // Sum of numbers from 1 to N using formula
    int totalSum = (N * (N + 1)) / 2;

    // Sum of array elements
    int sum = 0;
    for (auto it : a) {
        sum += it;
    }

    // Missing number = totalSum - sum of array
    return totalSum - sum;
}
/*
Time Complexity (TC): O(N) → Single pass through array
Space Complexity (SC): O(1) → Constant extra space
*/


// 🔹 Approach 3: XOR Method
int missingNumber(vector<int>& a, int N) {
    int totalXor = 0, xor1 = 0;

    // XOR all array elements
    for (int i = 0; i < a.size(); i++) {
        xor1 ^= a[i];
        totalXor ^= (i + 1);
    }

    // XOR with N to include last number
    totalXor ^= N;

    // XOR of totalXor and xor1 gives missing number
    return totalXor ^ xor1;
}
/*
Time Complexity (TC): O(N) → Single pass through array
Space Complexity (SC): O(1) → Constant extra space
Note: XOR method works because x^x = 0 and x^0 = x
*/

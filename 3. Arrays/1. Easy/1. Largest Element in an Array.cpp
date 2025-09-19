/*
https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1&leftPanelTabValue=PROBLEM
*/



#include <bits/stdc++.h> 
using namespace std;

// ✅ Approach 1: Using sorting
// Sort the array and return the last element (largest)
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) (in-place sort)
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    return arr[n-1]; // last element is the largest
}

// ✅ Approach 2: Using linear scan
// Traverse array and track maximum element
// Time Complexity: O(n)
// Space Complexity: O(1)
int largestElement(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    for(auto it : arr) {
        if(it > maxi) {
            maxi = it; // update maximum
        }
    }
    return maxi;
}

/*
  https://www.naukri.com/code360/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h>
using namespace std;

// ✅ Approach 1: Using Sorting
// 1. Sort the array
// 2. Find the element just smaller than the largest (2nd max)
// 3. Find the element just greater than the smallest (2nd min)
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) extra
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    vector<int> ans;
    int smaxi = INT_MIN, smini = INT_MAX;

    // find second largest
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != a[n - 1]) { // first smaller than largest
            smaxi = a[i];
            ans.push_back(smaxi);
            break;
        }
    }

    // find second smallest
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) { // first larger than smallest
            smini = a[i];
            ans.push_back(smini);
            break;
        }
    }
    return ans;
}

// ✅ Approach 2: Without Sorting (Efficient)
// 1. Track largest, second largest
// 2. Track smallest, second smallest
// 3. Update values while traversing array
// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int maxi = a[0], smaxi = INT_MIN;
    int mini = a[0], smini = INT_MAX;

    for (int i = 1; i < n; i++) {
        // 🔹 Update largest and second largest
        if (a[i] > maxi) {
            smaxi = maxi;
            maxi = a[i];
        }
        else if (a[i] < maxi && a[i] > smaxi) { 
            // candidate for 2nd largest
            smaxi = a[i];
        }

        // 🔹 Update smallest and second smallest
        if (a[i] < mini) {
            smini = mini;
            mini = a[i];
        }
        else if (a[i] > mini && a[i] < smini) {
            // candidate for 2nd smallest
            smini = a[i];
        }
    }

    vector<int> ans;
    ans.push_back(smaxi);
    ans.push_back(smini);
    return ans;
}

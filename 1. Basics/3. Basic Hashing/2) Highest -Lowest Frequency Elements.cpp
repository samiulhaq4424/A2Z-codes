// https://www.codingninjas.com/studio/problems/k-most-occurrent-numbers_625382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


/*
Problem:
--------
Given an array 'v' of 'n' integers, find:
1. The element with the highest frequency (if multiple elements have same frequency → pick the smallest)
2. The element with the lowest frequency (if multiple elements have same frequency → pick the smallest)

Example:
--------
Input: v = [1, 2, 3, 1, 1, 4]

Step 1: Build frequency map
- 1 → 3 times
- 2 → 1 time
- 3 → 1 time
- 4 → 1 time

Step 2: Find max frequency element
- Max frequency = 3 → element = 1

Step 3: Find min frequency element
- Min frequency = 1 → elements = 2,3,4 → pick smallest = 2

Output: [1, 2]

Approach:
---------
1. Use an unordered_map to count frequency of each element.
2. Initialize:
   - minFreq = INT_MAX, minVal = INT_MAX
   - maxFreq = INT_MIN, maxVal = INT_MIN
3. Iterate through the map:
   - For max frequency:
       - If current frequency > maxFreq → update maxFreq and maxVal
       - If current frequency == maxFreq → pick smaller element using min(maxVal, element)
   - For min frequency:
       - If current frequency < minFreq → update minFreq and minVal
       - If current frequency == minFreq → pick smaller element using min(minVal, element)
4. Return {maxVal, minVal}

Time Complexity (TC):
--------------------
- O(n) → one pass to count + one pass over the map

Space Complexity (SC):
---------------------
- O(n) → map stores frequencies of each unique element
*/

vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int,int> mp;

    // Count frequency of each element
    for(auto it : v) {
        mp[it]++;
    }

    int minFreq = INT_MAX, minVal = INT_MAX;
    int maxFreq = INT_MIN, maxVal = INT_MIN;

    // Determine max and min frequency elements
    for(auto it : mp) {
        int element = it.first;
        int count = it.second;

        // Check for maximum frequency
        if(count > maxFreq){
            maxFreq = count;
            maxVal = element;
        }
        else if(count == maxFreq) {
            maxVal = min(maxVal, element);  // pick smallest if tie
        }

        // Check for minimum frequency
        if(count < minFreq){
            minFreq = count;
            minVal = element;
        }
        else if(count == minFreq){
            minVal = min(minVal, element);  // pick smallest if tie
        }
    }

    return {maxVal, minVal};
}

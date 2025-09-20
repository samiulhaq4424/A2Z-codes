// Problem: Sum of all divisors of numbers from 1 to n
// Link: https://www.codingninjas.com/studio/problems/sum-of-all-divisors_8360720?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

/* 
==============================
Brute-force approach
==============================
- For each number i = 1 to n, calculate sum of divisors of i
- To find sum of divisors of i, loop from 1 to i and add all numbers that divide i

Time Complexity (TC): O(n^2)
  - countDivisor(i) runs in O(i)
  - sumOfAllDivisors loops over 1..n → O(1+2+3+..+n) ≈ O(n^2)
Space Complexity (SC): O(1)
*/

int countDivisor(int val) {
    int ans = 0;
    for(int i = 1; i <= val; i++) {
        if(val % i == 0) {
            ans += i;   // add divisor to sum
        }
    }
    return ans;
}

int sumOfAllDivisors(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += countDivisor(i);  // sum divisors of i
    }   
    return sum;
}


/* 
==============================
Optimized approach
==============================
- Observation: Every divisor 'd' contributes to all multiples of 'd'
- Number of multiples of d ≤ n = n/d
- Contribution of d = d * (n/d)
- Sum over all d = 1..n

Time Complexity (TC): O(n)
  - Loop runs 1..n and calculates contribution in O(1)
Space Complexity (SC): O(1)
*/

int sumOfAllDivisorsOptimized(int n){
    long long sum = 0;
    for(int d = 1; d <= n; d++){
        sum += d * (n / d);  // d contributes to floor(n/d) numbers
    }
    return sum;
}

/*
Example:
---------
Input: n = 5
Divisors of 1 = {1} → sum=1
Divisors of 2 = {1,2} → sum=3
Divisors of 3 = {1,3} → sum=4
Divisors of 4 = {1,2,4} → sum=7
Divisors of 5 = {1,5} → sum=6
Total = 1+3+4+7+6 = 21
*/
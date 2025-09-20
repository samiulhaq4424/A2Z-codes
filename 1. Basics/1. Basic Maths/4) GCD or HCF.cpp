// https://www.codingninjas.com/studio/problems/hcf-and-lcm_840448?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    // Keep applying Euclidean algorithm until one becomes 0
    while(b != 0) {
        int temp = b;
        b = a % b;  // remainder
        a = temp;
    }
    return a; // when b=0, a is the gcd
}

//The Euclidean algorithm runs in O(log(min(a, b)))

/*
📌 How it works:
---------------
gcd(a, b) = gcd(b, a % b)
Repeat until b = 0 → then a is the gcd

📌 Example:
gcd(56, 98)
= gcd(98, 56)
= gcd(56, 42)
= gcd(42, 14)
= gcd(14, 0) → gcd = 14
*/

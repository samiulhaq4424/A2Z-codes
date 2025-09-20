// https://www.codingninjas.com/studio/problems/palindrome-number_624662?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


bool palindrome(int n) {
    int rem = 0;        // to store each extracted digit
    int palin = 0;      // reversed number
    int nums = n;       // copy of original number

    // build reverse of n
    while(nums) {
        rem = nums % 10;          // extract last digit
        nums = nums / 10;         // remove last digit
        palin = palin * 10 + rem; // append digit to reversed number
    }

    // if reversed == original → it's a palindrome
    return palin == n;
}

/*
📌 Problem:
-----------
Check if a number is a palindrome (reads same forward and backward).

📌 Example:
-----------
Input: n = 121
Reverse = 121 → true

Input: n = 123
Reverse = 321 → false

📌 Approach:
------------
- Copy original number.
- Reverse it digit by digit.
- Compare reversed number with original.

📌 Complexity:
--------------
Time Complexity: O(d) where d = number of digits in n
Space Complexity: O(1)
*/

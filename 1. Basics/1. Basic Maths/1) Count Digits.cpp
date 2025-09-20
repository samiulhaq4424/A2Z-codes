// https://www.codingninjas.com/studio/problems/count-digits_8416387?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


int countDigits(int n) {
    int cnt = 0;     // counter for digits that divide n
    int rem = 0;     
    int nums = n;    // store original number (for divisibility checks)

    while(n > 0) {
        rem = n % 10;   // extract last digit
        n = n / 10;     // remove last digit

        // check divisibility (ignore digit 0 to avoid division by zero)
        if(rem != 0 && nums % rem == 0) {
            ++cnt;
        }
    }

    return cnt;  // return count of digits that divide original number
}

/*
📌 Problem:
-----------
Count how many digits of a number n evenly divide n itself.

📌 Example:
-----------
Input: n = 1012
Digits = [1, 0, 1, 2]
Divisible digits = 1, 1, 2  → count = 3

📌 Approach:
------------
- Extract each digit (using % 10).
- Skip digit if it's 0 (division by 0 not allowed).
- Check if n % digit == 0 → increment count.
- Return total count.

📌 Complexity:
--------------
Time Complexity: O(d) where d = number of digits in n
Space Complexity: O(1) (only variables used)
*/

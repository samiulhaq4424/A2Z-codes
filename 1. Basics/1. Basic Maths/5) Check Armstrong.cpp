// https://www.codingninjas.com/studio/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


int countDigits(int num){
    int cnt = 0;
    while(num){
        num = num / 10;   // remove last digit
        ++cnt;            // increment digit count
    }
    return cnt;           // return total number of digits
}

bool checkArmstrong(int n){
    int armNum = 0, nums = n;
    
    // Step 1: Count digits in number
    int noOfDigits = countDigits(n);

    // Step 2: Reconstruct Armstrong sum
    while(nums) {
        int rem = nums % 10;                  // extract last digit
        nums = nums / 10;                     // remove last digit
        armNum = armNum + pow(rem, noOfDigits); // add digit^noOfDigits
    }

    // Step 3: Check if Armstrong number
    return armNum == n;
}



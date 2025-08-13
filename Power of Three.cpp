// *****************Approch 1 **************************

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// *****************Approch 2 ***************************

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};

// *********************Approch 3 **********************

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        if(n == 1){
            return true;
        }

        return n%3 == 0 && isPowerOfThree(n/3);
    }
};

// *************************Approch 4 *******************

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        double x = log10(n) / log10(3);
        return x == (int)x;
    }
};
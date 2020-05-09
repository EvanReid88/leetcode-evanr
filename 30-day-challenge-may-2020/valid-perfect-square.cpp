// https://leetcode.com/problems/valid-perfect-square/

// O(sqrt(n))
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i <= num / i; i++) {
            if (i * i == num) {
                return true;
            }
        }
        
        return false;
    }
};


// all square numbers are sum of odd numbers starting from 1
// O(sqrt(n))
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        
        return num == 0;
    }
};

// TODO binary search O(log(n))
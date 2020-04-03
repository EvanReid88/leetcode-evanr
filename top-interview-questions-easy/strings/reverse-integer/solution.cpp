// https://leetcode.com/problems/reverse-integer

// first attempt o(n)
// O(log(x))
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int remainder;
        while (x != 0) {
            remainder = x % 10;

            // catch integer overflows
            int limit = INT_MAX / 10;
            if (result > limit || result < -limit) return 0;
            
            result = result * 10 + remainder;
            x /= 10;
        }
        
        return result;
    }
};
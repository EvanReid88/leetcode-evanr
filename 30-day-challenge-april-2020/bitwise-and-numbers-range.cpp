// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// O(n - m) time
// O(1) space
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // perform bitwise AND
        // from range end to start
        while (n > m) {
            n &= n - 1;
        }
        
        return n;
    }
};
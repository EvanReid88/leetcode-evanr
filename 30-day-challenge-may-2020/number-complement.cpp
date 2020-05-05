// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        // keep one number shift to left until can no longer be shifted
        // at same time, shift right by 1 and take XOR for compliment
        for (int i = 0; copy != 0; i++) {
            copy >>= 1;
            num ^= (1 << i);
        }
        
        return num;
    }
};
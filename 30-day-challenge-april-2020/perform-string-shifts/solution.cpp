// https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299/

// first attempt
// O(s.length * 2)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int totalShift = 0;
        int len = s.length();
        
        // calculate total shift
        for (auto a: shift) {
            totalShift += a[0] ? a[1] : -a[1];
        }
        
        // calculate the number of right shifts necessary
        // to shift to resulted string
        // (n left shifts is equal to length - n right shifts)
        int  k = abs(totalShift) % len;
        int numShifts = totalShift >= 0 ? k: len - k;
        
        // copy characters to resulted index after numShifts shifts
        string result(len, ' ');
        for (int i = 0; i < len; i++) {
            int shiftIdx = (numShifts + i) % len;
            result[shiftIdx] = s[i];
        }
        
        return result;
    }
};
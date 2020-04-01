// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int lastDigitIdx = digits.size() - 1;
        digits[lastDigitIdx]++;
        for (int i = lastDigitIdx; i >= 0; i--) {
            if (digits[i] >= 10) {
                digits[i] = 0;
                if (i) {
                    digits[i - 1]++;  
                }
                else { 
                    digits.insert(digits.begin(), 1);
                }
            }
        }
        return digits;
    }
}; 
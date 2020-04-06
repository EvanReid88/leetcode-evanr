// https://leetcode.com/problems/string-to-integer-atoi/

// first attempt
// O(n)
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int sign = 1;
        int signSet = false;
        for (int i = 0; i < str.length(); i++) {
            // if sign has not been set and char is a space, continue
            if (!signSet && str[i] == ' ') continue;
            
            // if sign has not been set and char is '-' or '+'
            // set the sign and set flag to true
            if (!signSet && (str[i] == '-' || str[i] == '+')) {
                sign = str[i] == '-' ? -1 : 1;
                signSet = true;
                continue;
            }
            
            // if char is valid digit
            if (str[i] >= '0' && str[i] <= '9') {

                // set sign to true if no sign was passed
                signSet = true;
                // check if result is out of range
                if (INT_MAX / 10 < result || (INT_MAX / 10 == result && INT_MAX % 10 < str[i] - '0')) {
                    return sign == -1 ? INT_MIN : INT_MAX;  
                    break;  
                }

                // multiply result by 10 and add digit
                result = (result * 10) + (str[i] - '0');
            }
            else break;
        }
        
        return sign * result;
    }
};
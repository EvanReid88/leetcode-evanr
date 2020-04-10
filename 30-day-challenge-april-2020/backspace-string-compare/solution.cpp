// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/


// first attempt
// two pass
class Solution {
public:
    void backspace(string &s) {
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '#') {
                if (i == 0) {
                    s.erase(0, 1);
                }
                else {
                    s.erase(i - 1, 2);
                    i--;    
                }
            } 
            else {
                i++;
            }
        }
    }
    
    bool backspaceCompare(string S, string T) {
        backspace(S);
        backspace(T);
        return S == T;
    }
};
// https://leetcode.com/problems/count-and-say


// first attempt
// O(N(result length))
class Solution {
public:
    void generateCountAndSay(string& result) {
        int count = 1;
        string s = "";
        for (int i = 1; i < result.length(); i++) {
            if (result[i] == result[i - 1]) {
                // if digit is same as previous, increase count
                count++;
            }
            else {
                // else append current count and previous digit
                // when read off: one (digit) or (count) (digit)s...
                s += to_string(count) + result[i - 1];
                count = 1;
            }
        }
        
        // add the last sequence
        s += to_string(count) + result[result.length() - 1];
        result = s;
    }
    
    string countAndSay(int n) {
        // first term in sequence
        string result = "1";
        
        // generate n - 1 in terms in sequence
        for (int i = 1; i < n; i++) {
            generateCountAndSay(result);
        }
        
        return result;
    }
};
// https://leetcode.com/problems/remove-k-digits/

// greedy approach
// O(N) Time
// O(N) Space
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0";
        stack<char> stack;
        
        // remove top digit if greater than current digit (char)
        for (char& c: num) {
            while (k > 0 && !stack.empty() && stack.top() > c) {
                stack.pop();
                k--;
            }
            
            stack.push(c);
        }
        
        // handle repeating characters edge case
        while (k > 0) {
            stack.pop();
            k--;
        }
        
        // create string from stack
        string result = "";
        while (!stack.empty()) {
            char current_char = stack.top();
            stack.pop();
            
            result = current_char + result;
        }
        
        // remove left trailing 0s
        while (result.length() > 1 && result[0] == '0') {
            result.erase(0, 1);
        }
        
        return result;
    }
};
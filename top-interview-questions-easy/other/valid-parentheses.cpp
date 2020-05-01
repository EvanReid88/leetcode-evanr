// https://leetcode.com/problems/valid-parentheses

// Stack / HashMap Solution
// O(n) Time
// O(n) Space
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;        
        stack<char> stack;
        
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        
        for (auto c: s) {
            if (map.find(c) != map.end()) {
                // get next value in stack. If empty, set dummy value
                char top = stack.empty() ? '#' : stack.top();
                stack.pop();
                
                // if the closing bracket for current char
                // does not match popped element, return false
                if (top != map[c]) {
                    return false;
                }
            }
            else {
                // push opening brackets to stack
                stack.push(c);
            }
        }
        
        // if stack empty, valid parentheses
        return stack.empty();
    }
};

// Stack / Swith Solution
// Stack Solution
// O(n) Time
// O(n) Space
class Solution {
public:
    bool isValid(string s) { 
        stack<char> stack;
        
        for (auto c: s) {
            switch(c) {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                    
                default: 
                    bool empty = stack.empty();
                    if (empty || c != stack.top()) return false;
                    stack.pop();
            }
        }
        
        // if stack empty, valid parentheses
        return stack.empty();
    }
};

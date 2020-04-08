// https://leetcode.com/problems/fizz-buzz/

// first attempt
// O(n)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; i++) {
            string entry = "";
            if (i % 3 == 0) {
                entry += "Fizz";
            }
            if (i % 5 == 0) {
                entry += "Buzz";
            }
            entry = entry == "" ? to_string(i) : entry;
            result.push_back(entry);
        }
        
        return result;
    }
};

// TODO hash solution
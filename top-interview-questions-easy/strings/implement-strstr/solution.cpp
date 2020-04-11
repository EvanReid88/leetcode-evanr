// https://leetcode.com/problems/implement-strstr/s

// first attempt
// O((haystack length)(needle length))
class Solution {
public:
    int strStr(string haystack, string needle) {
        // return 0 if needle is empty string
        if (needle.empty()) return 0;
        
        // iterate until the first index of last possible needle
        for (int i = 0; i + needle.size() - 1 < haystack.size(); i++) {
            bool found = true;
            
            // check if the haystack substring matches needle
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) return i;
        }
        
        // return -1 if needle not found
        return -1;
    }
};
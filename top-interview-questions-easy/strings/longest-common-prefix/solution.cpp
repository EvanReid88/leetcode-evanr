// https://leetcode.com/problems/longest-common-prefix

// first attempt
// O(S)  s sum of all chars in string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        bool common = true;
        int i = 0;
        
        // return "" if empty list
        if (strs.empty()) return result;
        while (common) {
            char first = ' ';
            
            // compare char at index i for each string in strs
            for (int j = 0; j < strs.size(); j++) {
                // if any string is empty string, lcp is ""
                if (strs[j] == "") return "";
                
                // set the character to compare from first string
                if (j == 0) first = strs[j][i];   
                
                // if char not equal 
                // or index out of range
                if (strs[j][i] != first ||
                    i == strs[j].length()) {
                    common = false;
                    break;
                }
            }
            
            // append common char to result
            if (common) result += first;
            i++;
        }
        
        return result;
    }
};

// TODO other vertical scanning solution
// https://leetcode.com/problems/reverse-string/

// first attempt
// O(n)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int endIdx = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++) {
            int temp = s[i];
            s[i] = s[endIdx - i];
            s[endIdx - i] = temp;
        }
    }
};

// same approach, but more obvious `two pointer`
// O(n)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; int j = (s.size() - 1);
        while(i < j) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
    }
};

// recursive solution
// O(n)
class Solution {
public:
    void reverseHelper(vector<char>& s, int i, int j) {
        if (i >= j) return;
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
        reverseHelper(s, i, j);
    }
    
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size() - 1);
    }
};

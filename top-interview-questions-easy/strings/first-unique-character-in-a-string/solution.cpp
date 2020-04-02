// https://leetcode.com/problems/first-unique-character-in-a-string

// O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (auto a: s) {
            map[a]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) return i;
        }
        
        return -1;
    }
};
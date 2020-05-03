// https://leetcode.com/problems/ransom-note/

// hashmap solution
// O(m + n) time
// O(n) space
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map(26);
        for (char& c: magazine) {
            map[c]++;
        }
        
        for (char& c: ransomNote) {
            if (--map[c] == -1) {
                return false;
            }
        }
        
        return true;
    }
};

// vector as hashmap solution
// O(m + n) time
// O(n) space
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26, 0);
        for (char& c: magazine) {
            vec[c - 'a']++;
        }
        
        for (char& c: ransomNote) {
            if (--vec[c - 'a'] == -1) {
                return false;
            }
        }
        
        return true;
    }
};

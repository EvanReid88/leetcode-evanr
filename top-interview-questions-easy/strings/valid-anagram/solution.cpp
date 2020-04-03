// https://leetcode.com/problems/valid-anagram

// hashmap solution
// O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> map;
        
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }
        
        for (auto x : map) {
            if (x.second) return false;
        }
        
        return true;
    }
};

// solution with array as hashmap 
// (since all entries are will be lowercase chars)
// O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int counts[26] = {0};
        for (int i = 0; i < s.length(); i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (counts[i]) return false;
        }
        return true;
    }
};

// sorting solution
// O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
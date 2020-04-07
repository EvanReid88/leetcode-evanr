// https://leetcode.com/problems/group-anagrams

// sorting solution
// O(NKlogK) (k max string length)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        unordered_map<string, vector<string>> map;
        
        for (auto a: strs) {
            string key = a;
            sort(key.begin(), key.end());
            
            // if no key exists for sorted string, insert empty vector
            if (map.find(key) == map.end()) {
                map.insert({key, {}});
            }
            
            // push string to vector at sorted key
            map[key].push_back(a);
        }
        
        // convert map values to vector
        vector<vector<string>> result;
        for (auto a: map) {
            result.push_back(a.second);
        }
        
        return result;
    }
};

// counting solution
// O(NK) (k max string length)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        unordered_map<string, vector<string>> map;
        vector<int> count(26);
        
        for (auto a: strs) {
            fill(count.begin(), count.end(), 0);
            
            for (auto c: a){
                count[c - 'a']++;   
            }
            
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += count[i];
            }
            if (map.find(key) == map.end()) {
                map.insert({key, {}});
            }
            map[key].push_back(a);
        }
        
        vector<vector<string>> result;
        for (auto a: map) {
            result.push_back(a.second);
        }
        
        return result;
    }
};

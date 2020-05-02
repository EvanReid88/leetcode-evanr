// https://leetcode.com/problems/jewels-and-stones/

// hashset solution
// O(m + n) time
// O(m) space
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<int> set;
        int result = 0;
        for (char& c: J) {
            set.insert(c);
        }
        for (char& c: S) {
            if (set.find(c) != set.end()) {
                result++;
            }
        }
        
        return result;
    }
};

// no extra space solution
// O(n^2) time (string.find() is O(n))
// O(1) space
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        for (char& c: S) {
            if (J.find(c) != string::npos) {
                result++;
            }
        }
     
        return result;
    }
};
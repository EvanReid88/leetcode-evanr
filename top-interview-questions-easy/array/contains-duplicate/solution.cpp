// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> numSet;
        for (auto a: nums) {
            if (numSet.find(a) != numSet.end()) {
                return true;
            } 
            numSet.insert(a);     
        }
        return false;
    }
};
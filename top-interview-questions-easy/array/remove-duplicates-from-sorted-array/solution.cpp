// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        while (i < nums.size()) {
            if (nums[i - 1] == nums[i]) {
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        
        return nums.size();
    }
};

// STL solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
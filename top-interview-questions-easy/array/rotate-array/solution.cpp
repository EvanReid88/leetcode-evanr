// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();

        vector<int> newVect(length);
        for (int i = 0; i < length; i++) {
            int rotateIdx = (k + i) % length;
            newVect[rotateIdx] = nums[i];
        }
        
        nums = newVect;
    }
};
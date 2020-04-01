// https://leetcode.com/problems/move-zeroes

// first Attempt
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i = 0; 
        while (i < size) {
            if (!nums[i]) {
                nums.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                size--;
            } 
            else {
                i++;
            }
        }
    }
};

// two pointer solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = 0;
        
        // if cur element not 0
        // append to the front of last non-0 element
        for (auto a: nums) {
            if (a != 0) {
                nums[lastNonZero++] = a;
            }
        }
        
        // all non-zero elements are in relative order
        // at front of array. fill remaining with 0s
        for (int i = lastNonZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
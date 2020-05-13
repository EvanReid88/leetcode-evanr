// https://leetcode.com/problems/single-element-in-a-sorted-array/

// binary search solution 
// O(logn) Time (binary search)
// O(1) Space
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool even = (right - mid) % 2 == 0;
            if (nums[mid] == nums[mid - 1]) {
                if (even) {
                    // move past duplicate
                    right = mid - 2;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[mid] == nums[mid + 1]) {
                if (even) {
                  // move past duplicate
                    left = mid + 2;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                // single element found
                return nums[mid];
            }
        }
        
        return nums[left];
    }
};
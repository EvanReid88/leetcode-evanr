// https://leetcode.com/problems/search-in-rotated-sorted-array/

// binary search solution
// O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        
        int left = 0;
        int right= nums.size() - 1;
        
        // loop will break when left is at smallest index
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // is middle element greater than furthest right element
            // (in un-shifted sorted array, this will always be true)
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        // reset index for normal binary search
        int start = left;
        left = 0;
        right = nums.size() - 1;
        
        // determine which side of smallest index to perform bs
        if (target >= nums[start] && target <= nums[right]) {
            left = start;
        }
        else {
            right = start;
        }
        
        // perform binary search on portion of nums
        // which would contain the target
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};
https://leetcode.com/problems/merge-sorted-array/

// O(m + n) Time
// O(1) space (in place)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty()) return;
        
        // last index of nums1
        int a = m - 1;
        // last index of nums2
        int b = n - 1;
        // last index of last element in merged array
        int i = m + n - 1;
        
        while (a >= 0 && b >= 0) {
            // compare numbers starting from end of nums1 and nums2
            // add greater num to end of merged array
            if (nums1[a] > nums2[b]) {
                nums1[i] = nums1[a];
                // go back one in nums1
                a--;
            }
            else {
                nums1[i] = nums2[b];
                // go back one in nums2
                b--;
            }
            // go back one in merged array
            i--; 
        }
        
        // if nums2 is longer than nums1
        // copy rest of nums2 to merged array
        while (b >= 0) {
            nums1[i] = nums2[b];
            i--;
            b--;
        } 
    }
};
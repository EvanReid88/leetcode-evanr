// https://leetcode.com/problems/first-bad-version/

// Binary Search Tree Solution
// O(logn) Time
// O(1) Space

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            // calculate middle 
            int middle = left + (right - left) / 2;
            
            if (isBadVersion(middle)) {\
                // if we are to right of first bad fersion
                right = middle;
            }
            else {
                // if we havent reached bad version
                left = middle + 1;
            }
        }
        
        return left;
    }
};
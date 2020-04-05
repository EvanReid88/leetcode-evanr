// https://leetcode.com/problems/maximum-subarray

// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = INT_MIN;
        for (auto a: nums) {
            if (curSum <= 0){
                curSum = a;
            } 
            else {
                curSum += a;
            } 
            if (curSum > maxSum) {
                maxSum = curSum;
            }
        }
        return maxSum;
    }
};
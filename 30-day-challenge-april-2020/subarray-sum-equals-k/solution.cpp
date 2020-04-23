// https://leetcode.com/problems/subarray-sum-equals-k/

// hashmap solution
// O(N) Time
// O(N) Space
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        
        // cumulated sum
        int sum = 0;
        // result count
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // if sums map contains sum - k sum
            // then array with sum k exists between 0 and i
            if (sums.find(sum - k) != sums.end()) {
                result += sums[sum - k];
            }
    
            sums[sum]++;
        }
        
        return result;
    }
};
// https://leetcode.com/problems/jump-game/

// O(N) Time
// O(1) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        
        if (len < 2) return true;
        int max = nums[0];
        
        for (int i = 0; i < len; i++) {
            if (max <= i && nums[i] == 0) {
                return false;
            }
            
            // update max
            if (max <= i + nums[i]) {
                max = i + nums[i];
            }
            
            // determine if max can reach last index
            if (max >= len - 1) {
                return true;
            }
        }
        
        return false;
    }
};
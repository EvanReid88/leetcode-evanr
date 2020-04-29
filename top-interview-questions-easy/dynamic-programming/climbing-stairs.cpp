// https://leetcode.com/problems/climbing-stairs/ 

// dynamic programming solution
// O(N) Time
// O(N) Space
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        
        vector<int> dp(n + 1);
        
        for (int i = 1; i <= n; i++) {
            if (i < 3) {
                dp[i] = i;
            }
            else {
                dp[i] = dp[i - 1] + dp[i - 2];    
            }
        }
        
        return dp[n];
    }
};

// TODO brute force solution
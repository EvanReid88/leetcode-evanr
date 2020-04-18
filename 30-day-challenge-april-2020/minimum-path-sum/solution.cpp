// https://leetcode.com/problems/minimum-path-sum/

// Time Complexity: O(M*N) grid size
// Space Complexity: O(M*N) initializing new grid
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid.size() == 0) return 0;
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] += grid[i][j];
                
                // if not in the first row or column
                if (i > 0 && j > 0) {
                    // get min value of cells above and to left of current
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                }
                // if not in first column
                else if (i > 0) {
                    // get value of cell above current
                    dp[i][j] += dp[i - 1][j];
                }
                // if not in first row
                else if (j > 0) {
                    // get value of cell to left of current
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
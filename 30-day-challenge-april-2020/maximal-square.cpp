// https://leetcode.com/problems/maximal-square/
// dynamic programming

// O(MN) time
// O(N) space (n columns)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        
        int cols = matrix[0].size();
        
        // create dp matrix
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        
        // track largest square
        int largest = 0;
        
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                
                // if char at index to top left of current is 1
                // we have possibility of extending max square
                if (matrix[i - 1][j - 1] == '1') {
                    
                    // get minimum value of largest possible square
                    // at left, top, and top left element of current
                    // if the value > 0, we have found a larger square
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    
                    // if current square is larger than largest
                    // set largest
                    if (largest < dp[i][j]) {
                        largest = dp[i][j];
                    }
                }
            }
        }
        
        // area of largest square
        return largest * largest;
    }
};
// https://leetcode.com/problems/rotate-image

// first attempt
// O((n/2)n)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        // rotate one 'layer' at a time
        for (int i = 0; i < len / 2; i++) {
            for (int j = i; j < len - i - 1; j++) {
                // set temp int to to top 
                int temp = matrix[i][j];
                
                // set top int to left
                matrix[i][j] = matrix[len - 1 - j][i];
                
                // set left int to bottom
                matrix[len - 1 - j][i] = matrix[len - 1 - i][len - 1 - j];
                
                // set bottom int to right
                matrix[len - 1 - i][len - 1 - j] = matrix[j][len - 1 - i];
                
                // set right int to temp
                matrix[j][len - 1 - i] = temp;
            }
        }
    }
};
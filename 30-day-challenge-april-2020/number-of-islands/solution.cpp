// https://leetcode.com/problems/number-of-islands/

// bfs solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    BFS(grid, i, j);
                }
            }
        }
        
        return count;
    }
    
    void BFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() 
         || j < 0 || j >= grid[i].size()
         || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0';
        
        // up
        BFS(grid, i + 1, j);
        // down
        BFS(grid, i - 1, j);
        // left
        BFS(grid, i, j + 1);
        // right
        BFS(grid, i, j - 1);
    }
};

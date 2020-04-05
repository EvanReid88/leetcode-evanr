// https://leetcode.com/problems/valid-sudoku/

// first attempt
// O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<char>> rowSetList = {{}, {}, {}, {}, {}, {}, {}, {}, {}}; 
        vector<unordered_set<char>> squareSetList = {{}, {}, {}, {}, {}, {}, {}, {}, {}}; 
        
        for (int i = 0; i < 9; i++) {
            unordered_set<char> colSet;
            for (int j = 0; j < 9; j++) {
                
                // get value at current position
                char value = board[i][j];
                if (value != '.') {
                    
                    // check row set
                    if (colSet.find(value) == colSet.end()) {
                        colSet.insert(value);
                    }
                    else {
                        return false;
                    }
                    
                    // check column set
                    if (rowSetList[j].find(value) == rowSetList[j].end()) {
                        rowSetList[j].insert(value);
                    }
                    else {
                        return false;
                    }
                    
                    // check square set
                    int squareNum = (i / 3) + 3 * (j / 3);
                    if (squareSetList[squareNum].find(value) == squareSetList[squareNum].end()) {
                        squareSetList[squareNum].insert(value);
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// TODO attempt with single hashmap;
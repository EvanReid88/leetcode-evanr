// https://leetcode.com/problems/check-if-it-is-a-straight-line/

// O(n) Time
// O(1) Space
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        
        double slope = 0.0;
        
        for (int i = 0; i < coordinates.size() - 1; i++) {
            // get slope 
            double x = coordinates[i][0] - coordinates[i + 1][0];
            double y = coordinates[i][1] - coordinates[i + 1][1];
            double currSlope = y / x;
            
            // if not first iteration, slope must be same for line to be straight
            if (i != 0) {
                if (currSlope != slope) {
                    return false;
                }
            } else {
                slope = currSlope;
            }
            
        }
        // if slope is consistant for each point, line is straight
        return true;
    }
};
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3306/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
// O(MN)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        
        if (rows == 0 || cols == 0) {
            return -1;
        }
        
        int result = -1;
        int r = 0;
        int c = cols - 1;
        
        while (r < rows && c >= 0) {
            if (binaryMatrix.get(r,c) == 1) {
                result = c;
                c--;
            }
            else {
                r++;
            }
        }
        
        return result;
    }
};
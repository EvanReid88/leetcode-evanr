// https://leetcode.com/problems/diameter-of-binary-tree/

// DFS solution
// O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depthOfBinaryTree(TreeNode* root, int& result) {
        if (root == NULL) return 0;
        
        int ldepth = depthOfBinaryTree(root -> left, result);
        int rdepth = depthOfBinaryTree(root -> right, result);
        
        // update result
        // diameter of tree is max value of:
        // left depth + right depth (+1)
        result = max(result, ldepth + rdepth);
        
        return 1 + max(ldepth, rdepth);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int result = INT_MIN;
        depthOfBinaryTree(root, result);
        
        return result;
    }
};
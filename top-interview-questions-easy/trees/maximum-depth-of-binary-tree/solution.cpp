// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// recursive solution
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        // recursively check right and left nodes
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        // determine greater depth
        int mDepth = max(lDepth, rDepth);
        
        return mDepth + 1;
    }
};
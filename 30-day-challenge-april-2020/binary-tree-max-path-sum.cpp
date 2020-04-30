// https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int max_path;
    int maxPathSum(TreeNode* root) {
        max_path = INT_MIN;
        pathSum(root);
        return max_path;
    }
    
    int pathSum(TreeNode* node) {
        if (node == NULL) return 0;
 
        int left = max(0, pathSum(node->left));
        int right = max(0, pathSum(node->right));
        
        max_path = max(max_path, left + right + node->val);
        return max(left, right) + node->val;
    }
};
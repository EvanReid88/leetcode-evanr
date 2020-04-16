// https://leetcode.com/problems/validate-binary-search-tree/

// recursive solution
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
 
    bool isValidBST(TreeNode* root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        
        // in order traversal
        return (root->val > min) && (root->val < max) &&
               isValidBST(root->left, min, root->val) && 
               isValidBST(root->right, root->val, max);
    }
};

// iterative inorder stack solution
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        long inOrder = LONG_MIN;
        
        while (!nodeStack.empty() || root != NULL) {
            while(root != NULL) {
                nodeStack.push(root);
                root = root->left;
            }
            root = nodeStack.top();
            nodeStack.pop();
            
            // if next element in an inorder traversal
            // is less than the previous, not bst
            if (root->val <= inOrder) return false;
            inOrder = root->val;
            root = root->right;
        }
        
        return true;
    }
};
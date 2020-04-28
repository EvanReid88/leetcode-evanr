// TODO finish

//https://www.techiedelight.com/check-given-binary-tree-symmetric-structure-not/

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
       
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        } 
        else if (right == NULL || left == NULL) {
            return false;
        }
        
        // check if mir
        if (left->val != right->val) return false;
        
        if (!isSymmetric(left->left, right->right)) return false;
        if (!isSymmetric(left->right, right->left)) return false;
        
        return true;
    }
};
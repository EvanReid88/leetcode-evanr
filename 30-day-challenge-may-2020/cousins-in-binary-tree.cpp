// https://leetcode.com/problems/cousins-in-binary-tree/

// recursive solution
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
    TreeNode* findParentDepth(TreeNode* root, int val, int depth, int& level) {
        if (!root) return nullptr;
        
        if ((root->left && root->left->val == val) || (root->right &&   root->right->val == val)) {
            level = depth;
            return root;
        }

        TreeNode* left = findParentDepth(root->left, val, depth + 1, level);
        if (left) return left;

        TreeNode* right = findParentDepth(root->right, val, depth + 1, level);
        if (right) return right;

        return nullptr;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) {
            return false;
        }
        
        int xDepth = -1;
        TreeNode* xParent = findParentDepth(root, x, 0, xDepth);
        
        int yDepth = -1;
        TreeNode* yParent = findParentDepth(root, y, 0, yDepth);
        
        // if parent of nodes x and y
        // are not equal, but at same depth,
        // x and y are cousins
        if (xParent != yParent && xDepth == yDepth) {
            return true;
        }
        
        return false;
    }
};

// hashmap solution
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
		  unordered_map<int, pair<int, int>> m;
		  helper(root, 0, -1, m);
		  return m[x].first == m[y].first && m[x].second != m[y].second;
    }
    void helper(TreeNode* node, int depth, int parent, unordered_map<int, pair<int, int>>& m) {
    	if (!node) return;
    	m[node->val] = {depth, parent};
    	helper(node->left, depth + 1, node->val, m);
    	helper(node->right, depth + 1, node->val, m);
    }
};
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// trees

// BFS solution
// O(vertices + edges) time
// O(vertices) space 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int size = queue.size();
            vector<int> currLevel;
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                currLevel.push_back(current->val);
                
                // check for left and right children
                if (current->left != NULL) {
                    queue.push(current->left);
                }
                if (current->right != NULL) {
                    queue.push(current->right);
                }
            }
            
            // add current level to result
            result.push_back(currLevel);
        }
        
        return result;
    }
};
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/
// DFS Solution

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
private:
    bool isValidSequence(TreeNode* root, int n, int pos, vector<int>& arr) {
        if (root == NULL
         || pos == n
         || root->val != arr[pos]) {
            return false;
        }
        else if (!root->left && !root->right && pos == n - 1) {
            return true;
        }
        
        return (isValidSequence(root->left, n, pos + 1, arr)
             || isValidSequence(root->right, n, pos + 1, arr));
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {

        int n = arr.size();
        int pos = 0;
        return isValidSequence(root, n, pos, arr);
    }
};

// simple solution
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr,int i=0) {
	//check if root is null but some elements of arr are left
        if( !root && i <= arr.size()-1 )
            return false;
	//if we are on the last element of arr, then check it is leaf condition
        if( i == arr.size()-1 ){
            return root->val == arr[i] && root->left == NULL && root->right == NULL;
        }
	// if root->val is same as arr index value, call for next values in arr 
	// on left and right subtrees
        return root->val == arr[i] && ( isValidSequence(root->left,arr,i+1) || 
                                     isValidSequence(root->right,arr,i+1) );
    }
};
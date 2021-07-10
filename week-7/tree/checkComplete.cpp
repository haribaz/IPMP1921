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
    int count(TreeNode *root) {
        if(root==NULL) {
            return 0;
        }
        
        return 1+count(root->left) + count(root->right);
    }
    
    bool helper(TreeNode* root, int n, int idx) {
        if(root==NULL) {
            return true;
        }
        if(idx >= n) {
            return false;
        }
        return helper(root->left, n, 2*idx+1) && helper(root->right, n, 2*idx+2);
    }
    bool isCompleteTree(TreeNode* root) {
        int n = count(root);
        return helper(root, n, 0);
    }
};
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
    bool helper(TreeNode* root, TreeNode **temp) {
        if(root == NULL) {
            return true;
        }
        
        bool a = helper(root->left, temp);
        if(*temp != NULL && root->val <= (*temp)->val)
            return false;
        *temp = root;
        bool b = helper(root->right, temp);
        return a && b;
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = NULL;
        return helper(root, &temp);
    }
};
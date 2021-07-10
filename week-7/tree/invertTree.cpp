class Solution {
public:
    void helper(TreeNode* root) {
        TreeNode* temp;
        if(root == NULL) {
            return;
        }
        invertTree(root->left);
        invertTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
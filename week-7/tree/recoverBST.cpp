class Solution {
public:
    void helper(TreeNode* root, TreeNode** first, TreeNode** second, TreeNode** prev) {
        if(!root) {
            return;
        }
        helper(root->left, first, second, prev);
        if(*prev != NULL && root->val < (*prev)->val) {
            if(!*first) {
                *first = *prev;
            }
            *second = root;
        }
        *prev = root;
        helper(root->right, first, second, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        helper(root, &first, &second, &prev);
        swap(first->val, second->val);
    }
};
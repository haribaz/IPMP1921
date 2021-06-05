class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root) {
            return countNodes(root->left) + countNodes(root->right) + 1;
        } else {
            return 0;
        }
    }
};
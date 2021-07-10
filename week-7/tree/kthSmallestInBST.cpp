class Solution {
public:
    int ans;
    void helper(TreeNode* root, int &x, int k) {
        if(root == NULL) {
            return;
        }
        helper(root->left, x, k);
        if(x == k) {
            ans = root->val;
        }
        x++;
        helper(root->right, x, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int x = 1;
        helper(root, x, k);
        return ans;
    }
};
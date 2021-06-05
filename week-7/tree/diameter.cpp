class Solution {
public:
    int d=0;
    
    int find(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        int lh = find(root->left);
        int rh = find(root->right);
        d = max(d, lh+rh+2);
        return max(lh,rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        find(root);
        return d;
    }
};
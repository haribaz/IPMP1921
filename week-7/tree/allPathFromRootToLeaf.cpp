class Solution {
public:
    void helper(TreeNode* root, string temp, vector<string> &res) {
        if(root == NULL) {
            return;
        }
        
        if(root->left == NULL && root->right == NULL) {
            temp += to_string(root->val);
            res.push_back(temp);
        }
        temp += to_string(root->val) + "->";
        helper(root->left, temp, res);
        helper(root->right, temp, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp = "";
        helper(root, temp, res);
        return res;
    }
};
class Solution {
public:
    
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            for(int i=1; i<=n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(i == n) {
                    res.push_back(node->val);
                }
                
                if(node->left) {
                    q.push(node->left);
                }
                
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};
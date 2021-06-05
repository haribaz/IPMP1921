class Solution {
public:
    
    int depth(TreeNode* root)     //function to find the no of levels in tree
{
    if(root==NULL)
        return 0;
    return 1+max(depth(root->left),depth(root->right));
}

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d);
        queue<TreeNode*> q;
          if(d==0)
              return res;
        q.push(root);
        int i=0;
        while(!q.empty()) {
            int count = q.size();
            while(count--) {
                TreeNode* node = q.front();
                res[d-1].push_back(node->val);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            d--;
        }
        return res;
    }
};
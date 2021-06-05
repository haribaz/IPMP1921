class Solution {
public:

    
    vector<vector<int>> levelOrder(TreeNode* root) {
      
        vector<vector<int>> res;
        queue<TreeNode*> q;
          if(root == NULL)
              return res;
        q.push(root);
        int i=0;
        while(!q.empty()) {
            int count = q.size();
            res.push_back(vector<int>());
            while(count--) {
                TreeNode* node = q.front();
                res[i].push_back(node->val);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            i++;
        }
        return res;
    }
};
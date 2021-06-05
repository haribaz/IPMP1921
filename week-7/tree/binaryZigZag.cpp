class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> res;
        if(root == NULL) {
            return res;
        }
         int i=0;
    s1.push(root);
    while(!s1.empty() || !s2.empty()) {
        if(!s1.empty())
        res.push_back(vector<int>());
    while(!s1.empty()) {
        
        TreeNode* temp = s1.top();
        res[i].push_back(temp->val);
        s1.pop();
    
        if(temp->left) {
            s2.push(temp->left);
        }
        
        if(temp->right) {
            s2.push(temp->right);
        }
    }
    i++;
        if(!s2.empty())
        res.push_back(vector<int>());
    while(!s2.empty()) {
        
        TreeNode* temp = s2.top();
        res[i].push_back(temp->val);
        s2.pop();

        if(temp->right) {
            s1.push(temp->right);
        }

        if(temp->left) {
            s1.push(temp->left);
        }
    }
        i++;
    }
        return res;
    }
};
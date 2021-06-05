class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int count = 0;
        int maxi = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            count = q.size();
            int start = q.front().second;
            int end = q.back().second;
            maxi = max(maxi, end-start+1);
            while(count--) {
                pair<TreeNode*, int> node = q.front();
                int i = node.second - start;
                q.pop();
                if(node.first->left)
                    q.push({node.first->left, 2*i+1});
                if(node.first->right)
                    q.push({node.first->right, 2*i+2});
            }
        }
        return maxi;
    }
};
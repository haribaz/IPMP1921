class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
    void util(TreeNode* root, map<int, vector<pair<int, int>>>& mp, int hd, int lvl){
        if(!root)
        return;
        
        util(root->left, mp, hd-1, lvl+1);
        mp[hd].push_back(make_pair(root->val, lvl));
        util(root->right, mp, hd+1, lvl+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        util(root, mp, 0, 0);
        map<int, vector<pair<int, int>>>::iterator it;
        vector<vector<int>> v;
        for(it = mp.begin(); it!=mp.end(); it++){
            sort(it->second.begin(), it->second.end(), comp);
            vector<int> tv;
            for(int i=0; i<it->second.size(); i++){
                tv.push_back(it->second[i].first);
            }
            v.push_back(tv);
        }
        return v;
    }
};
class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> temp, int index, int target, vector<int> &candidates) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        
       
        for(int i = index; i<candidates.size(); i++) {
            if(i!=index && candidates[i] == candidates[i-1]) {
                continue;
            } 
            
            if(candidates[i] > target) {
                break;
            }
                temp.push_back(candidates[i]);
                helper(res, temp, i+1, target-candidates[i], candidates);
                temp.pop_back();
            
        
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(res, temp, 0, target, candidates);
        return res;
    }
};
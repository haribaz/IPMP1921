class Solution {
public:
    
    void helper(vector<int> &nums, int l, int r, vector<vector<int>> &res, vector<int> temp) {
        if(l==r) {
            res.push_back(temp);
            return;
        }
        
        for(int i=l; i<=r; i++) {
            swap(temp[l], temp[i]);
            helper(nums, l+1, r, res, temp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = nums;
        helper(nums, 0, nums.size()-1, res, temp);
        return res;
    }
};
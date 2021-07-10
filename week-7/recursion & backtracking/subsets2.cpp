class Solution {
public:
    
    void helper(vector<vector<int>> &res, vector<int> temp, int idx, vector<int> &nums) {
        res.push_back(temp);
        for(int i=idx; i<nums.size(); i++) {
            if(i!=idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(res, temp, i+1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, 0, nums);
        return res;
    }
};
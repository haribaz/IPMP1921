class Solution {
public:
    
    void backtrack(vector<int> arr, int idx, vector<vector<int>> &res, vector<int> temp) {
    if(idx == arr.size()) {
        res.push_back(temp);
        return;
    }
    temp.push_back(arr[idx]);
    backtrack(arr, idx+1, res, temp);
        temp.pop_back();
    backtrack(arr, idx+1, res, temp);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, 0, res, temp);
        return res;
    }
};
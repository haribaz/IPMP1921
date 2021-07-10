class Solution {
public:
    
    int helper(vector<int> nums, int index, int XOR) {
        if(index == nums.size()) {
            return XOR;
        }
        
        int with = helper(nums, index+1, XOR^nums[index]);
        int without = helper(nums, index+1, XOR);
        return with + without;
    }
    
    
    
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};
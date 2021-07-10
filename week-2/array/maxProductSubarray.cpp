class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<n; i++) {
            int temp = currMax;
            currMax = max({currMax*nums[i], currMin*nums[i], nums[i]});
            currMin = min({temp*nums[i], currMin*nums[i], nums[i]});
            ans = max(ans, currMax);
        }
        return ans;
    }
};
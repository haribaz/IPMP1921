class Solution {
public:
    
    int max(int a, int b) { 
        return (a > b) ? a : b; 
    }
 
    int max(int a, int b, int c) { 
    return max(max(a, b), c); 
    }
    
    int crossingSum(vector<int> &nums, int l, int m, int r) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i >= l; i--) {
        sum = sum + nums[i];
        if (sum > left_sum)
            left_sum = sum;
    }
        
        sum=0;
        int right_sum = INT_MIN;
        for (int i = m+1; i <= r; i++) {
        sum = sum + nums[i];
        if (sum > right_sum)
            right_sum = sum;
    }
        
        return max(left_sum + right_sum, left_sum, right_sum);
    }
    
    int helper(vector<int>& nums, int l, int r) {
         if(l == r) {
             return nums[l];
         }
        
        int m = l + (r-l)/2;
        return max(helper(nums, l, m), 
                   helper(nums, m+1, r),
                   crossingSum(nums, l ,m ,r));
    }
    
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
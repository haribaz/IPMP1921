class Solution {
public:
    
    int count(vector<int> &nums, int k, int l, int r) {
        int count = 0;
        for(int i=l; i<=r; i++) {
            if(nums[i] == k) {
                count++;
            }
        }
        return count;
    }
    
    int DAC(vector<int> &nums, int l, int r) {
        if(l == r) {
            return nums[l];
        }
        
        int m = l + (r-l)/2;
        int left = DAC(nums, l, m);
        int right = DAC(nums, m+1, r);
        
        if(left == right) {
            return left;
            
        }
        
        int lCount = count(nums, left, l, r);
        int rCount = count(nums, right, l , r);
        
        return lCount > rCount ? left : right;
    }
    
    
    
    int majorityElement(vector<int>& nums) {
        return DAC(nums, 0, nums.size()-1);
    }
};
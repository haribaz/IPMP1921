class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int s=0, e=n-1, i, min, max;
        for(s=0; s<n-1; s++) {
            if(nums[s] > nums[s+1]) {
                break;
            }
        }
        
        if(s == n-1) {
            return 0;
        }
        
        for(e=n-1; e>0; e--) {
            if(nums[e] < nums[e-1]) {
                break;
            }
        }
        
        min = nums[s];
        max = nums[s];
        for(i=s+1; i<=e; i++) {
            if(nums[i] > max)
                max = nums[i];
            
            if(nums[i] < min)
                min = nums[i];
        }
        
        for(i=0; i<s; i++) {
            if(nums[i] > min) {
                s = i;
            }
        }
        
        for(i=n-1; i>e; i--) {
            if(nums[i] < max) {
                e = i;
            }
        }
        
        return e-s+1;
    }
};
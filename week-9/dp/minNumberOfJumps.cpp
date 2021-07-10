class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || nums[0] == 0) {
            return 0;
        }
        int jumps[n];
        
        jumps[0] = 0;
        for(int i=1; i<n; i++) {
            jumps[i] = INT_MAX;
            for(int j=0; j<i; j++) {
                if(nums[j] + j >= i) {
                    jumps[i] = min(jumps[i], jumps[j]+1);
                }
            }
        }
        return jumps[n-1];
    }
};
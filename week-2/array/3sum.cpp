class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX; 
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<size-2 && diff != 0; i++) {
            int l = i+1;
            int h = size-1;
            while(l<h) {
                int sum = nums[i] + nums[l] + nums[h];
                if(abs(target - sum) <= abs(diff)) {
                    diff = target - sum;
                }
                
                if(sum < target) {
                    l++;
                } else {
                    h--;
                }
            }
        }
        return target - diff;
    }
};
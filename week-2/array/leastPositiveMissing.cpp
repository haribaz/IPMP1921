class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int p=0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                if(nums[i]==p){

                }else if(nums[i]==p+1){
                    p++;
                }else{
                    return p+1;
                }
            }
        }
        return p+1;
    }
};
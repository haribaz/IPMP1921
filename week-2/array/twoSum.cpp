class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> ans;
        unordered_map<int, int> map;
        
        for(i=0; i<nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        for(i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end() && map.find(complement)->second != i) {
                ans.push_back(i);
                ans.push_back(map.find(complement)->second);
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = *max_element(nums1.begin(), nums1.end());
        m = min(m, *max_element(nums2.begin(), nums2.end()));
        vector<bool> present1(m+1,0);
        vector<bool> present2(m+1,0);   
        for(auto n: nums1)
        {
            if(n<=m)
                present1[n]=true;
        }
        for(auto n: nums2){
            if(n<=m)
               present2[n]=true;
        }    
        vector<int> res;
        for(int i=0; i<=m; i++)
        {
            if(present1[i] && present2[i])
                res.push_back(i);
        }
        return res;
    }
};
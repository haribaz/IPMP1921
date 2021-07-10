class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int l=0, r=m;
        
        while(l<=r) {
            int a = l + (r-l)/2;
            int b = (m+n+1)/2 - a;
            
            int l1 = a == 0 ? INT_MIN : nums1[a-1];
            int l2 = b == 0 ? INT_MIN : nums2[b-1];
            int r1 = a == m ? INT_MAX : nums1[a];
            int r2 = b == n ? INT_MAX : nums2[b];
            
            if(l1 <= r2 && l2 <= r1) {
                if((m+n)%2 == 0)
                    return (max(l1, l2) + min(r1, r2))/2.0;
                else
                    return max(l1, l2);
            } else if(l1 > r2) {
                r = a-1;
            } else {
                l = a+1;
            }
        }
        return 0.0;
    }
};
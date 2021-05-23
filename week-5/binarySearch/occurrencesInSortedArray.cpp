class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int first = -1, last= -1;
        int l=0, r=arr.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            
            if(arr[mid] == target) {
                first = mid;
                r = mid-1;
            } else if(arr[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        l=0, r=arr.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            
            if(arr[mid] == target) {
                last = mid;
                l = mid+1;
            } else if(arr[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
            return {first, last};
    }
};
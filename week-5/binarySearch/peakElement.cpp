public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, r=arr.size()-1;
        while(l<=r) {
            if(l==r) {
                return l;
            } 
            
            if(l + 1 == r) {
                if(arr[l] > arr[r]) {
                    return l;
                } else {
                    return r;
                }
            }
            int mid = l + (r-l)/2;
            if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])) {
                return mid;
            } else if((arr[mid] > arr[mid-1]) && (arr[mid] < arr[mid+1])) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int j = m+n-1;
        for(int i=m-1; i>=0; i--) {
            nums1[j] = nums1[i];
            j--;
        }
        int i = n, k=0;
        j=0;
        while(i<(m+n) && (j<n)) {
            if(nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i<(m+n)) {
            nums1[k++] = nums1[i++];
        }
        
        while(j<n) {
            nums1[k++] = nums2[j++];
        }
        for(int i=0; i<nums1.size(); i++) {
            cout<<nums1[i]<<" ";
        }
    }

    int main() {
        vector<int> nums1{4, 5 ,6};
        vector<int> nums2{1, 2, 3, 4, 5};
        merge(nums1, 3, nums2, 5);
    }
class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int left=0, right=A.size()-1;
        while(left<right) {
            if(A[left]%2 == 0) {
                left++;
            } else {
                swap(A[left], A[right]);
                right--;
            }
        }
        return A;
    }
};
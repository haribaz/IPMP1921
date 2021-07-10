class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int l, r;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSum = INT_MIN;
        for(l=0; l<cols; l++) {
            vector<int> temp(rows, 0);
            for(r=l; r<cols; r++) {
                for(int i=0; i<rows; i++) {
                    temp[i] += matrix[i][r];
                } 
                    set<int> s;
                s.insert(0);
                    int currSum = 0;
                    for(int j=0; j<rows; j++) {
                        currSum += temp[j];
                        auto target = s.lower_bound(currSum-k);
                        if(target != s.end()) {
                            maxSum = max(maxSum, currSum - *target);
                        }
                        s.insert(currSum);
                    }
            }
        }
        return maxSum;
    }
};
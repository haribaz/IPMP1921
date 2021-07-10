class Solution {
public:
    
    int mini(int a, int b, int c) {
        return min(a, min(b,c));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int dp[rows][columns];
        int largest = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                if(i==0 || j==0) {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                    largest = max(largest, dp[i][j]);
                } else if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + mini(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                    largest = max(largest, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return largest*largest;
    }
};
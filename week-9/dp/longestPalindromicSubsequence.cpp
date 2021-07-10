class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            }
        
        for(int i=0; i<n-1; i++) {
           if(s[i] == s[i+1]) {
               dp[i][i+1] = 2;
           } else {
               dp[i][i+1] = max(dp[i][i], dp[i+1][i+1]);
           }
        }
        
        
        for(int size = 3; size <=n; size++) {
            for(int i=0; i<n-size+1; i++) {
                if(s[i] == s[i+size-1]) {
                    dp[i][i+size-1] = 2 + dp[i+1][i+size-2];
                } else {
                    dp[i][i+size-1] = max(dp[i][i+size-2], dp[i+1][i+size-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
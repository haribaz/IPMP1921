class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<long long>> dp(d, vector<long long>(target+1, 0));
        
        for(int j=1; j<=target && j<=f; j++) {
            dp[0][j] = 1;
        }
        
        for(int i=1; i<d; i++) {
            for(int j=1; j<=target; j++) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%1000000007;
                if(j > f) {
                    dp[i][j] -= dp[i-1][j-f-1];
                }
                if(dp[i][j]<0) {
                    dp[i][j] += 1000000007;
                }
            }
        }
        return dp[d-1][target]%1000000007;
    }
};
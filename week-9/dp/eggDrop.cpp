class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        for(int i=1; i<=k; i++) {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        
        for(int i=1; i<=n; i++) {
            dp[i][1] = i;
        }
        
        for(int i=2; i<=n; i++) {
            for(int j=2; j<=k; j++) {
                dp[i][j] = INT_MAX;
                int low=1, high=i;
                while(low <= high) {
                    int mid = (low+high)/2;
                    int left = dp[mid-1][j-1];
                    int right = dp[i-mid][j];
                    int temp = max(left, right) + 1;
                    dp[i][j] = min(dp[i][j], temp);
                    if(left < right) {
                        low = mid+1;
                    } else {
                        high = mid-1;
                    }
                }
        }
       
    }
         return dp[n][k];
    }
};
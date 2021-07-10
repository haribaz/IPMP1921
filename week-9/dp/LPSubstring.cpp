class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        pair<int, int> p;
        int max = 1;
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            p= {i, 1};
            }
        
        for(int i=0; i<n-1; i++) {
           if(s[i] == s[i+1]) {
               dp[i][i+1] = 1;
               p = {i, 2};
               max = 2;
           } else {
               dp[i][i+1] = 0;
           }
        }
        
        
        for(int size = 3; size <=n; size++) {
            for(int i=0; i<n-size+1; i++) {
                if(s[i] == s[i+size-1] && dp[i+1][i+size-2] == 1) {
                    dp[i][i+size-1] = 1;
                    if(size > max) {
                    max = size;
                    p = {i, size};
                    }
                } else {
                    dp[i][i+size-1] = 0;
                }
            }
        }
        return s.substr(p.first, p.second);
    }
};
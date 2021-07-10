class Solution {
public:
    
    void helper(vector<vector<string>>&res, vector<string> temp, string s, int idx, vector<vector<int>> &dp) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            if(dp[idx][i] == 1) {
                temp.push_back(s.substr(idx, i-idx+1));
                helper(res, temp, s, i+1, dp);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> temp;
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            dp[i][i] = 1;
            }
        
        for(int i=0; i<n-1; i++) {
           if(s[i] == s[i+1]) {
               dp[i][i+1] = 1;
           } else {
               dp[i][i+1] = 0;
           }
        }
        
        
        for(int size = 3; size <=n; size++) {
            for(int i=0; i<n-size+1; i++) {
                if(s[i] == s[i+size-1] && dp[i+1][i+size-2] == 1) {
                    dp[i][i+size-1] = 1;
                } else {
                    dp[i][i+size-1] = 0;
                }
            }
        }
        helper(res, temp, s, 0, dp);
        return res;
    }
};
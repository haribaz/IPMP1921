class Solution {
public:
    
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) 
                return false;
        }
        return true;
    }
    
    void helper(vector<vector<string>>&res, vector<string> temp, string s, int idx) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i-idx+1));
                helper(res, temp, s, i+1);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> temp;
        helper(res, temp, s, 0);
        return res;
    }
};
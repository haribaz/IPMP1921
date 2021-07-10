class Solution {
public:
    void helper(vector<string> &res, int n, int open, int close, string current) {
        if(current.size() == n *2) {
            res.push_back(current);
            return;
        }
        
        if(open < n) {
            helper(res, n, open+1, close, current + "(");
        }
        
        if(close < open) {
            helper(res, n, open, close+1, current + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, 0, 0, "");
        return res; 
    }
};
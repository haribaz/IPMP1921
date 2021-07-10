class Solution {
public:
    
    void helper(vector<string> &res, string output, vector<string> dictionary, string digits, int i=0) {
        if(i == digits.size()) {
            res.push_back(output);
            return;
        }
        
        int c = digits[i] - '0';
        if(c == 0 || c == 1) {
            helper(res, output, dictionary, digits, i+1);
        }
        
         for(int j=0;j<dictionary[c].size();j++)
        {
            helper(res, output+dictionary[c][j], dictionary, digits ,i+1);
            
        }
        
        return;
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string output = "";
        vector<string> dictionary = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.size() == 0) {
            return res;
        }
        helper(res, output, dictionary, digits);
        return res;
    }
};
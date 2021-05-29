class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        for(; i < s.size() && s[i] == '1'; i++);
        if(i == s.size()) return true;
        for(; i < s.size() && s[i] == '0'; i++);
        if(i == s.size()) return true;
        return false;
    }
};
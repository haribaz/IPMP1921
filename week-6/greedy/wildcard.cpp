class Solution {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0;
        int pIndex = 0;
        int index = -1;
        int matchIndex = 0;
        
        while(sIndex < s.size()) {
            if(pIndex < p.size() && ((s[sIndex] == p[pIndex]) || p[pIndex] == '?')) {
                sIndex++;
                pIndex++;
            } else if(pIndex < p.size() && p[pIndex] == '*') {
                index = pIndex;
                pIndex++;
                matchIndex = sIndex;
            } else if(index != -1) {
                matchIndex++;
                sIndex = matchIndex;
                pIndex = index + 1;
            } else {
                return false;
            }
        }
        while(pIndex < p.size() && p[pIndex] == '*') {
            pIndex++;
        }
        
        return pIndex == p.size();
    }
};
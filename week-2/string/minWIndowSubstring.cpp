class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        
        for(char i='A'; i<='z'; i++) {
            mp[i] = 0;
        }
        for(int i=0; i<t.size(); i++) {
            mp[t[i]]++;
        }
        
        int count = t.size();
        int start=0, end=0;
        int minIndex = 0; 
        int minLength = INT_MAX;
        
        while(end < s.size()) {
            if(mp[s[end]] > 0) {
                count--;
            }
            mp[s[end]]--;
            end++;
            
            while(count == 0) {
               if(end - start < minLength) {
                   minLength = end - start;
                   minIndex = start;
               }
                mp[s[start]]++;
                if(mp[s[start]] > 0) {
                    count++;
                }
                start++;
            }
            
        }
        if(minLength == INT_MAX) {
                return "";
            }
        return s.substr(minIndex, minLength);
        
        
        
    }
};
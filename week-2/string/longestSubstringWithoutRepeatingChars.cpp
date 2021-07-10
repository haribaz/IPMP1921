class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int slow = 0;
        int fast = 0;
        int maxi = INT_MIN;
        unordered_set<char> st;
        while(fast < s.length()) {
            if(st.find(s[fast]) == st.end()) {
                st.insert(s[fast]);
                fast++;
                int t = st.size();
                maxi = max(maxi, t);
            } else {
                st.erase(s[slow]);
                slow++;
            }
        }
        return maxi;
    }
};
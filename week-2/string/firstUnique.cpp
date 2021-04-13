class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> map;
        for(int i=0; i<s.size(); i++) {
            map[s[i]].first++;
            map[s[i]].second = i;
        }
        int first = INT_MAX;
        int flag=0;
        for(auto itr=map.begin(); itr!=map.end(); itr++) {
            if(itr->second.first == 1) {
                flag = 1;
                if(itr->second.second < first) {
                    first = itr->second.second;
                }
            }
            
        }
        if(flag) {
            return first;
        } else {
            return -1;
        }
    }
};
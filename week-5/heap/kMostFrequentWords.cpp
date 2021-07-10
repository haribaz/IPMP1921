class Solution {
public:
    struct comp {
        bool operator()(pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        
        for(int i=0; i<n; i++) {
            mp[words[i]]++;
        }
        
        for(auto it: mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
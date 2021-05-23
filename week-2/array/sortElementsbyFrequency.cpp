#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
    if(p1.second.second != p2.second.second) {
        return p1.second.second > p2.second.second;
    } else {
        return p1.second.first < p2.second.first;
    }
}

void sortByFrequency(vector<int> arr) {
    unordered_map<int, pair<int, int>> map;
    for(int i=0; i<arr.size(); i++) {
        if(map.find(arr[i]) != map.end()) {
            map[arr[i]].second++;
        } else {
            map[arr[i]] = {i, 1};
        }
    }

    vector<pair<int, pair<int, int>>> res;
    for(auto it = map.begin(); it !=  map.end(); it++) {
        res.push_back({it->first, it->second});
    }

    sort(res.begin(), res.end(), compare);

    for(int i=0; i<res.size(); i++) {
        int count = res[i].second.second;
        while(count--) {
            cout<<res[i].first<<" ";
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 99, 2, 1, 1, 3, 66 ,3, 5 ,2};
    sortByFrequency(arr);
}
#include<bits/stdc++.h>
using namespace std;

void unionArray(vector<int> a, vector<int> b) {
    int maxi = *max_element(a.begin(), a.end());
    int realMax = max(maxi, *max_element(b.begin(), b.end()));
    vector<bool> present1(realMax+1, false);
    vector<bool> present2(realMax+1, false);
    vector<int> res;
    for(auto i: a) {
        present1[i] = true;
    }

    for(auto i: b) {
        present2[i] = true;
    }
    
    for(int i=0; i<=realMax; i++) {
        if(present1[i] || present2[i]) {
            res.push_back(i);
        }
    }

    for(auto i: res) {
        cout<<i<<" ";
    }

}


int main() {
    vector<int> a{1, 2, 2, 3, 4};
    vector<int> b{2, 2, 2, 4, 5};
    unionArray(a, b);
}
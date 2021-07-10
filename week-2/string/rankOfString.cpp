#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    int ans=1;
    for(int i=2; i<=n; i++) {
          ans *= i;
    }
    return ans;
}

pair<int, int> count(string s, int l ,int r) {
    int lesser=0;
    for(int i=l+1; i<=r; i++) {
           if(s[i] < s[l])
           lesser++;
    }

    unordered_map<char, int> mp;
    for(int i=l; i<=r; i++) {
        mp[s[i]]++;
    }

    int div=1;
    for(auto ele: mp) {
        div *= fact(ele.second);
    }

    return {lesser, div};
}
int findRank(string s) {
    int n = s.size();
    int tot = fact(n);
    int rank=1;
    pair<int, int> p;
    for(int i=0; i<n; i++) {
        tot /= n-i;

        p = count(s, i, n-1);
        rank += tot*p.first/p.second;
    }
    return rank;
}

int main() {
    string s= "ksllabs";
    cout<<findRank(s);
}
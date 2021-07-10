#include<bits/stdc++.h>
using namespace std;

void permutation(string s, int l, int r) {
    if(l==r) {
        cout<<s<<endl;
        return;
    }

    for(int i=l; i<=r; i++) {
        swap(s[i], s[l]);
        permutation(s, l+1, r);
        swap(s[i], s[l]);
    }
    
}

int main() {
    string s = "abcd";
    int n = s.size();
    permutation(s, 0, n-1);
}
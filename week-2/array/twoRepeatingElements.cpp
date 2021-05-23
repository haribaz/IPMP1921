#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a) {
    int n = a.size();
    int k = a.size()- 2;
    int XOR=0, x=0, y=0;
    int rmb = 0;
    for(auto x: a){
          XOR ^= x;
    }
    for(int i=1; i<=k; i++) {
        XOR ^= i;
    }
    
    rmb = XOR & (~XOR + 1);
    for(int i=0; i<n; i++) {
        if(a[i] & rmb) {
            x = x ^ a[i];
        } else {
            y = y ^ a[i];
        }
    }

    for(int i=1; i<=k; i++) {
        if(i & rmb) {
            x = x ^ i;
        } else {
            y = y ^ i;
        }
    }
    cout<<x<<" "<<y;
}

int main() {
    vector<int> a{1, 2, 3, 5, 4, 4, 3};
    helper(a);
}
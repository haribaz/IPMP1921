#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a) {
    int n = a.size();
    int XOR=0, x=0, y=0;
    int rmb = 0;
    for(auto x: a){
          XOR ^= x;
    }
    
    rmb = XOR & (~XOR + 1);
    for(int i=0; i<n; i++) {
        if(a[i] & rmb) {
            x = x ^ a[i];
        } else {
            y = y ^ a[i];
        }
    }
    cout<<x<<" "<<y;
}

int main() {
    vector<int> a{10, 10, 12, 5, 5, 6, 1, 1};
    helper(a);
}
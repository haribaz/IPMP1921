#include<bits/stdc++.h>
using namespace std;

void atooooi(string s) {
    int n = s.size();
    int out = 0;
    for(int i=0; i<n; i++) {
        out = out * 10 + (s[i] - '0');
    }
    cout<<out;
}

int main() {
    string s = "1234";
    atooooi(s);
}
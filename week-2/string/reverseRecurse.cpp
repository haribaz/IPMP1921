#include<bits/stdc++.h>
using namespace std;

void letsgo(string &s, int a, int b) {
    if(a < b) {
        char temp;
        temp = s[a];
        s[a++] = s[b];
        s[b--] = temp;
        letsgo(s, a, b);
    } else {
        return;
    }
}

int main() {
    string s = "Hello World";
    int n = s.size();
    letsgo(s, 0, n-1);
    cout<<s;
}
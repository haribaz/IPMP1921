#include<bits/stdc++.h>
using namespace std;

void encode(string s) {
    int n = s.size();
    for(int i=0; i<n; i++) {
        int count = 1;
        while(i<n-1 && s[i] == s[i+1]) {
            count++;
            i++;
        }
        cout<<s[i]<<count;
    
    }
}

int main() {
    string s = "wwwwaaadexxxxxxywww";
    encode(s);
}
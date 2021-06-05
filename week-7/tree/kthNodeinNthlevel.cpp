#include<bits/stdc++.h>
using namespace std;

string complement(string s) {
    string res = "";
    int i=0;
    while(s[i] != '\0') {
         if(s[i] == '0') {
             res += '1';
         } else {
             res += '0';
         }
         i++;
    }
    return res;
}

string helper(int level) {
    if(level == 0) {
        return "0";
    }

    string beforeLevel = helper(level-1);
    return beforeLevel + complement(beforeLevel);
}

int main() {
    string s = helper(3);
    int k = 1;
    cout<<s[k-1];
}
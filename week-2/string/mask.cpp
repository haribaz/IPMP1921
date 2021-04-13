#include<bits/stdc++.h>
using namespace std;

void removeChar(string input, string mask) {
    int count[256];
    for(int i=0; i<mask.size(); i++) {
        count[mask[i]]++;
    } 
    
    for(int i=0; i<input.size(); i++) {
           if(count[input[i]] == 0) {
               cout<<input[i];
           }
    }
}

int main() {
    string s1 = "Hello World";
    string s2 = "Wave Hi";
    removeChar(s1, s2);
}
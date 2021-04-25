#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 9;
    int k = log2(n & (~n+1)) + 1;
    cout<<k;
}
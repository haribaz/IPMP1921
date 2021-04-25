#include<bits/stdc++.h>
using namespace std;

int leftRotate(int n, int k) {
    return (n << k)|(n >> (32-k));
}

int rightRotate(int n, int k) {
    return (n >> k)|(n << (32-k));
}
int main() {
     int n=16;
     int k=2;
     cout<<leftRotate(n, k)<<endl;
     cout<<rightRotate(n, k)<<endl;
}
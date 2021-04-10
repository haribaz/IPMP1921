#include<bits/stdc++.h>
using namespace std;

pair<int, int> nonRepeating(vector<int> arr) {
    int n = arr.size();
    int x=0, y=0;
    int XOR = 0;
    int rmb;
    for(int i=0; i<n; i++) {
         XOR = XOR^arr[i];
    }

    rmb = (XOR) & (~XOR + 1);
    for(int i=0; i<n; i++) {
           if(arr[i] & rmb) {
               x = x^arr[i];
           } else {
               y = y^arr[i];
           }
    }
    return {x, y};
 }

int main() {
    vector<int> arr{1, 4, 5, 1, 5, 6, 3, 4, 8, 8};
    pair<int, int> p = nonRepeating(arr);
    cout<<p.first<<" "<<p.second;
}
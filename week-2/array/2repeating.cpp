#include <bits/stdc++.h>
using namespace std;

void repeating(vector<int> &arr) {
     int n = arr.size();
     unordered_map<int, int>map;
     for(int i=0; i<n; i++) {
         map[arr[i]]++;
     }
     for(int i=0; i<map.size(); i++) {
         if(map[i] > 1) {
             cout<<i<<endl;
         }
     }
     return;
}

int main() {
    vector<int> arr{4, 2, 4, 5, 2, 3, 1};
    repeating(arr);
}

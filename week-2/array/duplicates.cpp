#include<bits/stdc++.h>
using namespace std;

void duplicates(vector<int> arr) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(arr[abs(arr[i])] > 0) {
                arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            cout<<abs(arr[i])<<" ";
        }
}
}

int main() {
    vector<int> arr{1, 2, 7, 5, 3, 3, 2, 7};
    duplicates(arr);
}
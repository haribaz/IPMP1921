#include<bits/stdc++.h>
using namespace std;

void missing(vector<int> arr) {
    int n = arr.size();
    int sum = 1;
    for(int i = 2; i<=n+1; i++) {
        sum += i;
        sum -= arr[i-2];
    }
    cout<<sum;
}

int main() {
    vector<int> arr{2, 1, 7, 4, 5, 6};
    missing(arr);
}
#include<bits/stdc++.h>
using namespace std;

int fixedPoint(int arr[], int n) {
    int l=0, r=n-1, m;
    while(l<=r) {
        m = l+(r-l)/2;
        if(arr[m] == m) {
            return m;
        } else if(arr[m] > m) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 5, 1 ,3 , 0};
    cout<<fixedPoint(arr, 5);
}
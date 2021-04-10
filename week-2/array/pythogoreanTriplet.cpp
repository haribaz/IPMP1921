#include<bits/stdc++.h>
using namespace std;

void triplet(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        arr[i] = arr[i] * arr[i];
    }
     sort(arr.begin(), arr.end());
     for(int i=n; i>=2; i--) {
         int l = 0;
         int h = i-1;
         while(l<h) {
             if(arr[l] + arr[h] == arr[i]) {
                 cout<<"Triplet Found"<<endl;
                 cout<<sqrt(arr[l])<<" "<<sqrt(arr[h])<<" "<<sqrt(arr[i]);
                 break;
             }

             if(arr[l] + arr[h] < arr[i])
             l++;
             else {
             h--;
             }
         }
         
     }
     
}

int main() {
    vector<int> arr{3, 1, 4, 6, 5};
    triplet(arr);
    return 0;
}
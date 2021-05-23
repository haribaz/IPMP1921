#include <bits/stdc++.h>
using namespace std;
 

pair<int, int> ceilSearch(int arr[], int low, int high, int x)
{   int ceil=-1, flr=-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == x) {
            return {arr[mid], arr[mid]};
        } else if(arr[mid] < x) {
            flr = arr[mid];
            low = mid+1;
        } else {
            ceil = arr[mid];
            high = mid-1;
        }
    }
    return {ceil, flr};
}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 11;
    pair<int, int> p = ceilSearch(arr, 0, n-1, x);
    cout<<"ceil: "<<p.first<<endl;
    cout<<"floor: "<<p.second<<endl;
     
    return 0;
}
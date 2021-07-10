#include<bits/stdc++.h>
using namespace std;
 
 
pair<int, int>  getMinMax(int arr[], int l, int r)
{
    if(l==r) {
        return {arr[l], arr[l]};
    } else if(l+1 == r) {
        if(arr[l] < arr[r]) {
            return {arr[l], arr[r]};
        } else {
            return {arr[r], arr[l]};
        }
    } else {
        int mid = l + (r-l)/2;
        pair<int, int> res;
        pair<int, int> left = getMinMax(arr, l, mid);
        pair<int, int> right = getMinMax(arr, mid+1, r);

        if(left.first < right.first) {
            res.first = left.first;
        } else {
            res.first = right.first;
        }

        if(left.second > right.second) {
            res.second = left.second;
        } else {
            res.second = right.second;
        }

        return res;
    }
}
 

int main()
{
    int arr[] = { 1000, 11, 445,
                  1, 330, 3000 };
    int arr_size = 6;
     
    pair<int, int> p = getMinMax(arr, 0, arr_size - 1);
                              
    cout << "Minimum element is "
         << p.first << endl;
    cout << "Maximum element is "
         <<  p.second;
          
    return 0;
}
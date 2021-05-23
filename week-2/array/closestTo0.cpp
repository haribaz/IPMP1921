#include <bits/stdc++.h>
using namespace std;
 
void minAbsSumPair(int arr[], int n)
{  
    int sum, min_sum = INT_MAX;
    int l = 0, r = n-1;
    int min_l = 0, min_r = n-1;
    sort(arr, arr+n);
     
    while(l < r)
    {
        sum = arr[l] + arr[r];
        if(abs(sum) < abs(min_sum))
        {
            min_sum = sum;
            min_l = l;
            min_r = r;
        }
        if(sum < 0)
            l++;
        else
            r--;
    }
     
    cout << arr[min_l] << " " << arr[min_r];
}
 
int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    minAbsSumPair(arr, n);
    return 0;
}
 

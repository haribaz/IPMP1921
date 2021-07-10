#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
    int i, j, maxi = 0;
    int msis[n];
 
    
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];
 
   
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if (arr[i] > arr[j])
                msis[i] = max(msis[i], msis[j] + arr[i]);
 
    for ( i = 0; i < n; i++ )
        if ( maxi < msis[i] )
            maxi = msis[i];
 
    return maxi;
}
 

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum of maximum sum increasing "
            "subsequence is " << maxSumIS( arr, n ) << endl;
    return 0;
}
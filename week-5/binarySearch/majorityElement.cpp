// C++ program to check for majority
// element in a sorted array
#include<bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int low, int high, int x);
 
bool isMajority(int arr[], int n, int x)
{
     int i = binarySearch(arr, 0, n-1, x);

     if(i == -1) {
         return false;
     }

     if(((i+ n/2) <= (n-1)) && arr[i+ n/2] == x) {
         return true;
     } else {
         return false;
              }
}
 
int binarySearch(int arr[], int low, int high, int x)
{
    while(low<=high) {
        int mid = low + (high-low)/2;
        if((mid == 0 || arr[mid-1] < x) && arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
           low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = { 1, 2, 3, 3, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
     
    if (isMajority(arr, n, x))
        cout << x << " appears more than "
             << n / 2 << " times in arr[]"
             << endl;
    else
        cout << x << " does not appear more than "
             << n / 2 << "  times in arr[]" << endl;
  
    return 0;
}
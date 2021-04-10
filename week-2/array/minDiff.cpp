#include <bits/stdc++.h>
using namespace std;
 

int minDiff(int arr[], int arr_size)
{
     
     int diff = arr[1] - arr[0];
      
     int max = arr[0];
     for(int i = 1; i < arr_size; i++)
     {    
       if (arr[i] - max < diff)                            
       diff = arr[i] - max;
        
       if (arr[i] > max)
       max = arr[i];                    
     }
      
     return diff;
}
 

int main()
{
  int arr[] = {1, 2, 90, 10, 110};
  int n = sizeof(arr) / sizeof(arr[0]);
   

  cout << "Minimum difference is " << maxDiff(arr, n);
 
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n)
{
  
  int dp[n+1][n+1];

  for(int i=0; i<=n; i++) {
      for(int j=0; j<=n; j++) {
          if(i==0 || j==0) {
              dp[i][j] = 0;
          } else if(j<i) {
              dp[i][j] = dp[i-1][j];
          } else {
              dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i]);
          }
      }
  }
  return dp[n][n];
}
 
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<cutRod(arr, size);
    return 0;
}
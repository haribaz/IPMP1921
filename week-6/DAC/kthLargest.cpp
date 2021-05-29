#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    int x = arr[r], i = l-1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] >= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
            
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}
 
int randomPartition(vector<int> &arr, int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n + l;
    swap(&arr[pivot], &arr[r]);
    return partition(arr, l, r);
}
 

int kthLargest(vector<int> &arr, int l, int r, int k)
{
    
    if (l<=r)
    {
        int pos = randomPartition(arr, l, r);
 
        if (pos == k-1)
            return arr[pos];
        if (pos > k-1) 
            return kthLargest(arr, l, pos-1, k);
        return kthLargest(arr, pos+1, r, k);
    }
 
    return INT_MAX;
}
 
int main()
{   
    vector<int> arr {1, 4, 2, 3, 5, 7, 9};
    cout<<kthLargest(arr, 0, 6, 1);
}
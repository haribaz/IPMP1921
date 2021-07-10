int sortK(int arr[], int n, int k)
{
     
    
    int size;
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);
 
    
    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for(int i=0; i<N; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count<N-1; count++) {
          
          int mini = INT_MAX, node;
          for(int i=0; i<N; i++) {
              if(mstSet[i] == false && key[i] < mini) {
                  mini = key[i];
                  node = i;
              }
          }
          mstSet[node] = true;
          for(auto it: adj[node]) {
              int x = it.first;
              int wt = it.second;
              if(mstSet[x] == false && wt<key[x]) {
                  key[x] = wt;
                  parent[x] = node;
              }
          }
    }

    for(int i=1; i<N; i++) {
        cout<<parent[i]<<" - "<<i<<endl;
    }
}
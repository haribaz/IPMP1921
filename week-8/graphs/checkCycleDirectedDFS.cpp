
    bool checkForCycle(int node, vector<int> &dfsVis, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1; 
        dfsVis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(checkForCycle(it, dfsVis, vis, adj)) 
                    return true; 
            }
            else if(dfsVis[it] == 1) 
                return true; 
        }
        dfsVis[node] = 0;
        return false; 
    }

	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V+1, 0);
        vector<int> dfsVis(V+1, 0);
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, dfsVis, vis, adj)) 
                   return true; 
	        }
	    }
	    
	    return false; 
	}

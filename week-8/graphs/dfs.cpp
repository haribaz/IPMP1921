void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &res) {
    res.push_back(node);
    vis[node] = 1;
    for(auto i: adj[node]) {
        if(vis[i] == -1) {
            dfs(i, vis, adj, res);
        }
    }
}


void helper(int v, vector<int> adj[]) {
    vector<int> res;
    vector<int> vis(v+1, -1);

    for(int i=1; i<=v; i++) {
        if(vis[i] == -1) {
            dfs(i, vis, adj, res);
        }
    }
}
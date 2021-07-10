vector<int> bfs(int v, vector<int> adj[]) {
    vector<int> res;
    vector<int> vis(v+1, -1);

for(int i=1; i<=V; i++) {
    if(vis[i] == -1) {
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()) {
            int src = q.front();
            q.pop();
            res.push_back(src);
            for(auto x: adj[src]) {
                if(vis[x] == -1) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
    }
    return res;
  }
}
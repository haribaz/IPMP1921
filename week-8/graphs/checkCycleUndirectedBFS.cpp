
void helper(int node, vector<int> adj[], vector<int> &vis) {
    queue<pair<int, int>> q;
    vis[node] = 1;
    q.push({node, -1});

    while(!q.empty()) {
        int x = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[x]) {
            if(vis[it] == -1) {
                 vis[it] = 1;
                 q.push({it, x});
            } else {
                if(parent != it) {
                    return true;
                }
            }
        }
    }
    return false;
}





bool checkCycle(int v, vector<int> adj[]) {
    vector<int> vis(v+1, -1);
    for(int i=1; i<=v; i++) {
        if(vis[i] == -1) {
            if(helper(i, adj, vis))
            return true;
        }
    }
    return false;
}
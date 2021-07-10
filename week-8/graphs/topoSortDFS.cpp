 void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for(auto i: adj[node]) {
        if(vis[i] == -1) {
            dfs(i, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> helper(int v, vector<int> adj[]) {
    vector<int> res;
    vector<int> vis(v+1, -1);
    stack<int> st;
    for(int i=1; i<=v; i++) {
        if(vis[i] == -1) {
            dfs(i, vis, adj, st);
        }
    }

    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}
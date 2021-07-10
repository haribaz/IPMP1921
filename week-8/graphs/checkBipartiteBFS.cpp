class Solution {
public:
    
    
    bool helper(int node, vector<vector<int>> &graph, vector<int> &color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto it: graph[x]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[x];
                    q.push(it);
                } else if(color[it] == color[x]) {
                        return false;
                }
            }
        }
        
        return true;
    }
    
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        for(int i=0; i<v; i++) {
            if(color[i] == -1) {
                if(!helper(i, graph, color)) {
                    for(int i=0; i<color.size(); i++) {
                    cout<<color[i]<<" ";
        }
                    return false;
                }
            }
        }
        return true;
    }
};
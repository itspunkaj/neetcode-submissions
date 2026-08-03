class Solution {
public:
    bool dfs(int node, int par, vector<vector<int>>&g, vector<int> &vis) {
        vis[node] = 1;
        for(auto adjNode : g[node]) {
            if(adjNode == par) continue;
            if(vis[adjNode]) return true;

            if(dfs(adjNode,node,g,vis)) return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n);
        bool isCycle = dfs(0,-1,g,vis);

        for(auto it : vis) {
            if(!it) return false;
        }

        return !isCycle;
    }
};

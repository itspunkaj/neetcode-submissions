class Solution {
public:
    bool dfs(int node, int par, vector<vector<int>>&g, vector<int>&vis) {
        vis[node] = 1;

        for(auto nei : g[node]) 
        {
            if(nei == par) continue;

            if(vis[nei]) return true;
            if(dfs(nei,node,g,vis)) return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> g(n+1);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            vector<int> vis(n+1);

            if(dfs(edges[i][0],-1,g,vis)) return edges[i];
        }

        return {};

        
    }
};

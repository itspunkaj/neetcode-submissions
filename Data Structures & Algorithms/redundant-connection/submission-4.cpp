class Solution {
public:
    int cycleStart = -1;
    unordered_set<int> cycleNodes;

    bool dfs(int node, int par, vector<vector<int>>&g, vector<int>&vis) {

        if(vis[node]) {
                cycleStart = node;
                return true;
            }
        vis[node] = 1;

        for(auto nei : g[node]) 
        {
            if(nei == par) continue;
            
            if(dfs(nei,node,g,vis)) {
                if(cycleStart != -1) cycleNodes.insert(node);
                if(cycleStart == node) cycleStart = -1;
                return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> g(n+1);
        vector<int> vis(n+1,0);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(1,-1,g,vis);

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycleNodes.count(u) && cycleNodes.count(v)) {
                return {u, v};
            }
        }
        return {};


        return {};

        
    }
};

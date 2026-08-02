class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n);

        vector<vector<int>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int,int>> q;

        vis[0] = 1;
        int visited = 0;
        q.push({0,-1});

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            visited++;

            for(auto adjNode:g[node]) {
                if(parent == adjNode) continue;
                if(vis[adjNode]) return false;

                    vis[adjNode] = 1;
                    q.push({adjNode,node});
            }
        }

        return n == visited;
    }
};

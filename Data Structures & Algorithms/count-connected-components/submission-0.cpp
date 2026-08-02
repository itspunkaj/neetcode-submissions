class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][1]].push_back(edges[i][0]);
            g[edges[i][0]].push_back(edges[i][1]);
        }

        vector<int> vis(n);

        queue<int> q;

        int comp = 0;

        for(int i = 0 ; i < n; i++) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = 1;
                comp++;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto adjNode : g[node]) {
                        if(!vis[adjNode]) {
                            vis[adjNode] = 1;
                            q.push(adjNode);
                        }
                    }
                }
            }
        }

        return comp;
    }
};

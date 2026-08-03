class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1);

        vector<vector<int>> g(n+1);

        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int> q;


        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 1) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();

            q.pop();

            for(auto adjNode: g[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] ==1) {
                    q.push(adjNode);
                } 
            }
        }

        unordered_set<int> st;

        for(int i = 1; i <= n; i++) {
            if(indegree[i] > 1) st.insert(i);
        }

        for(int i = edges.size()-1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if(st.find(u) != st.end() && st.find(v) != st.end()) {
                return edges[i];
            }
        }

        return {};
    }
};

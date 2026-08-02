class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n);

        vector<vector<int>> g(n);

        for (int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        stack<int> st;

        while (!q.empty()) {
            int node = q.front();
            st.push(node);
            q.pop();

            for (auto adjNode : g[node]) {
                indegree[adjNode]--;
                if (!indegree[adjNode]) q.push(adjNode);
            }
        }

        vector<int> ans;
        if (st.size() != n) return ans;
        while (!st.empty()) {
            ans.push_back(st.top());

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

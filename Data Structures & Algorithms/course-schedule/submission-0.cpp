class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> g(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for(auto adjNode : g[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return count == numCourses;
    }
};

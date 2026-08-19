class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);

        for(auto flight:flights) {
            g[flight[0]].push_back({flight[1], flight[2]});
        } 

        vector<vector<int>> dist(n, vector<int>(k+2,INT_MAX));

        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int,int>, int>>> pq;

        pq.push({{0,0},src});

        dist[src][0] = 0;

        while(!pq.empty()) {
            auto frontNode = pq.top();
            int stops = frontNode.first.first;
            int node = frontNode.second;

            pq.pop();

            for(auto it : g[node]) {
                int adjNode = it.first;
                int w = it.second;
                if(stops < k+1 && dist[adjNode][stops+1] > dist[node][stops] + w) {
                    dist[adjNode][stops+1] = dist[node][stops] + w;

                    pq.push({{stops+1,dist[adjNode][stops+1]},adjNode});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 1; i < k+2; i++) {
            if(dist[dst][i] != INT_MAX) {
                ans = min(ans, dist[dst][i]);
            }
        }

        return ans == INT_MAX ? -1 :  ans;

    }
};

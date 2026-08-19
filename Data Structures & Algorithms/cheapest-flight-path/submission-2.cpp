class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);

        for(auto flight:flights) {
            g[flight[0]].push_back({flight[1], flight[2]});
        } 

        vector<int> dist(n, INT_MAX);

        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int,int>, int>>> pq;

        pq.push({{0,0},src});

        dist[src] = 0;

        while(!pq.empty()) {
            auto frontNode = pq.top();
            int stops = frontNode.first.first;
            int d = frontNode.first.second;
            int node = frontNode.second;

            pq.pop();

            for(auto it : g[node]) {
                int adjNode = it.first;
                int w = it.second;
                if(stops < k+1 && dist[adjNode] > d + w) {
                    dist[adjNode] = d + w;

                    pq.push({{stops+1,dist[adjNode]},adjNode});
                }
            }
        }

        

        return dist[dst] == INT_MAX ? -1 :  dist[dst];

    }
};

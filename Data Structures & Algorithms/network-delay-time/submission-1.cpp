class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);

        vector<int> dist(n+1,INT_MAX);

        for(auto time : times) {
            int u = time[0], v= time[1], t = time[2];

            g[u].push_back({v,t});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({k,0});

        while(!pq.empty()) {
            int node = pq.top().first;
            int d = pq.top().second;
            pq.pop();
            if(d > dist[node]) continue;

            for(auto it : g[node]) {
                int adjNode = it.first, w = it.second;
                if(dist[adjNode] > dist[node] + w) {
                    dist[adjNode] = dist[node] + w;
                    pq.push({adjNode, dist[node] + w});
                }
            }
        }

        int mint = *max_element(dist.begin()+1,dist.end());
        return mint == INT_MAX ? -1 : mint;
    }
};

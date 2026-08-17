class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        map<pair<int,int>,int> vis;

        for(auto it:points) {
            int x = it[0], y = it[1];

            vis[{x,y}] = 0;
        }

        pq.push({0,{points[0][0],points[0][1]}});

        int ans = 0;

        while(!pq.empty()) {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(vis[{x,y}]) continue;
            vis[{x,y}] = 1;

            ans += d;

            for(int i = 0; i < points.size(); i++) {
                int xj = points[i][0], yj = points[i][1];

                if(xj == x && yj == y) continue;

                int d = abs(x-xj) + abs(y - yj);

                if(!vis[{xj,yj}]) {
                    pq.push({d,{xj,yj}});
                }
            }
        }

        return ans;

    }
};

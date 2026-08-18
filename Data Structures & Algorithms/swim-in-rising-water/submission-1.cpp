class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0] = grid[0][0];

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({dist[0][0], {0,0}});

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int d = node.first;
            int x = node.second.first;
            int y = node.second.second;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                if(dist[nx][ny] > max(dist[x][y],grid[nx][ny])) {
                    dist[nx][ny] = max(dist[x][y],grid[nx][ny]);
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }

        return dist[n-1][m-1];
    }
};

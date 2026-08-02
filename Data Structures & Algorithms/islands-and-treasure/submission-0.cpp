class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({0,{i,j}});
                }
            }
        }

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

        while(!q.empty()) {
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;

                if(grid[nx][ny]!=-1 && grid[nx][ny] > d + 1) {
                    grid[nx][ny] = d + 1;
                    q.push({d+1,{nx,ny}});
                }
            }
        }

    }
};

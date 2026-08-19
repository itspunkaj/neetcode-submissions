class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        int total = 0;
        int rot = 0;

        for(int i = 0;i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    rot++;
                }
            }
        }

        if(total == 0) return 0;

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();
            ans++;
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    if(grid[nx][ny] == 0) continue;

                    if(grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        rot++;
                    }
                }
            }
        }

        return total == rot ? ans-1 : -1;
    }
};

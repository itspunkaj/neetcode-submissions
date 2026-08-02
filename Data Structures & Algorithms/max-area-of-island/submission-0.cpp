class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int area = 1;
                    grid[i][j] = 0;
                    q.push({i,j});

                    while(!q.empty()) {
                        int sz = q.size();

                        while(sz--) {
                            int x = q.front().first;
                            int y = q.front().second;

                            q.pop();


                            for(int k = 0; k < 4; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];

                                if(nx >= n || nx <0 || ny >= m || ny <0) continue;

                                if(grid[nx][ny]) {
                                    grid[nx][ny] = 0;
                                    q.push({nx,ny});
                                    area++;
                                }
                            }
                        }
                    }

                    ans = max(ans,area);
                }
            }
        }

        return ans;
    }
};

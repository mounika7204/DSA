class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(auto e : guards)
        {
            vis[e[0]][e[1]] = 2;
        }
        for(auto e : walls)
        {
            vis[e[0]][e[1]] = 2;
        }
        int rr[4] = {-1,0,1,0};
        int cc[4] = {0,1,0,-1};

        for(auto g : guards)
        {
            for(int k=0;k<4;k++)
            {
                int r = g[0],c=g[1];
                int nr = rr[k] + r;
                int nc = cc[k] + c;
                while(nr >=0 && nr < m && nc >=0 && nc < n)
                {
                    if (vis[nr][nc] == 2) break; 
                    if (vis[nr][nc] == 0) vis[nr][nc] = 1; 
                    nr += rr[k];
                    nc += cc[k];
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int rc[4] = {-1,0,1,0};
    int cc[4] = {0,1,0,-1}; 
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int stindex = entrance[0];
        int endindex = entrance[1];
        queue<pair<int,int>> q;
        q.push({stindex, endindex}); 
        maze[stindex][endindex] = '+';
         int ans=0;
        while(!q.empty())
        {
            int size = q.size();
            for(int j=0;j<size;j++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if((r==0 || r==maze.size()-1 || c==0 || c==maze[0].size()-1))
                {
                    if(r!=stindex || c!=endindex)
                {
                    return ans;
                }
                }
                for(int i=0;i<4;i++)
                {
                    int nr = r + rc[i];
                    int nc = c + cc[i];
                    if(nr >=0 && nr<maze.size() && nc>=0 && nc<maze[0].size() && maze[nr][nc] == '.')
                    {
                        maze[nr][nc] = '+';
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
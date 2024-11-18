class Solution {
public:
    int GetLiveN(vector<vector<int>>& board, int i, int j, int n, int m)
    {
        vector<pair<int,int>> d = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1},
            {0,1}
        };
        int alive = 0;
        for(auto dir : d)
        {
            int ni = 0,nj = 0;
            ni = i+dir.first;
            nj = j+dir.second;
            if(ni >= 0 && ni<m && nj >=0 && nj<n)
            {
                if(board[ni][nj] == 1 || board[ni][nj] == 3)
                {
                    alive++;
                }
            }
        }
        return alive;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int liven = GetLiveN(board, i, j, n, m);
                if(board[i][j] == 0)
                {
                    if(liven == 3)
                    {
                        board[i][j] = 2; //for newly alive;
                    }
                }
                else if(board[i][j] == 1)
                {
                    if(liven < 2 || liven > 3)
                    {
                        board[i][j] = 3; //newly dead;
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 3) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
          vector<vector<int>> dp(r, vector<int>(c,0));
           int s=0;
       for(int i=0;i<r;i++)
       {
           if(matrix[i][0] == 1)
           {
               dp[i][0] = 1;
               s++;
           }
       }
       for(int j=1;j<c;j++)
       {
           if(matrix[0][j] == 1)
           {
               dp[0][j] = 1;
               s++;
           }
       }
        for(int i =1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[i][j] == 1)
                {
                    dp[i][j] = 1 + min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
                }
                s+= dp[i][j];
            }
        }
        return s;
    }
};
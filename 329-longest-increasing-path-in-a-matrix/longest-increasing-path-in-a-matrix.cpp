class Solution {
public:
    int dp[200][200];
    int rec(int i, int j, vector<vector<int>>& matrix)
    {
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up=0,down=0,left=0,right=0;
        if(i + 1 < matrix.size() && matrix[i+1][j] > matrix[i][j])
        {
            up = rec(i+1, j, matrix);
        }
        if(i - 1 >= 0 && matrix[i-1][j] > matrix[i][j])
        {
            down = rec(i-1, j, matrix);
        }
        if(j + 1 < matrix[0].size() && matrix[i][j+1] > matrix[i][j])
        {
            left = rec(i,j+1,matrix);
        }
        if(j - 1 >= 0 && matrix[i][j-1] > matrix[i][j])
        {
            right = rec(i, j-1, matrix);
        }
        dp[i][j] = max({up,down,left,right}) + 1;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans, rec(i, j, matrix));
            }
        }
        return ans;
    }
};
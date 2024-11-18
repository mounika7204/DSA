class Solution {
public:
    // int rec(string s, string t, int n, int m, int i, int j)
    // {
    //     if(i>=n||j>=m) return 0;
    //     if(s[i] == t[j])
    //     {
    //         return 1 + rec(s,t,n,m,i+1,j+1);
    //     }
    //     else
    //     {
    //         return rec(s,t,n,m,i,j+1);
    //     }
    // }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        // int len = rec(s,t,n,m,0,0);
        // if(rec(s,t,n,m,0,0) == n)
        //     return true;
        // return false;
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Initialize dp[0][j] = 1 for all j, because an empty s is always a subsequence of any prefix of t
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 1;
        }
        
        // Fill DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                  
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                   
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[n][m] == 1;
    }
};
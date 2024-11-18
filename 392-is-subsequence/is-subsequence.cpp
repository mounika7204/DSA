class Solution {
public:
    int rec(string s, string t, int n, int m, int i, int j)
    {
        if(i>=n||j>=m) return 0;
        if(s[i] == t[j])
        {
            return 1 + rec(s,t,n,m,i+1,j+1);
        }
        else
        {
            return rec(s,t,n,m,i,j+1);
        }
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int len = rec(s,t,n,m,0,0);
        cout<<len<<endl;
        if(rec(s,t,n,m,0,0) == n)
            return true;
        return false;
    }
};
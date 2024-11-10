class Solution {
public:
    vector<vector<int>> res;
    void rec(int st, int n, int k, vector<int>& comb)
    {
        if(comb.size() == k)
        {
            res.push_back(comb);
            return;
        }
        for(int i=st;i<=n;i++)
        {
            comb.push_back(i);
            rec(i+1, n, k, comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        rec(1, n, k, comb);
        return res;
    }
};
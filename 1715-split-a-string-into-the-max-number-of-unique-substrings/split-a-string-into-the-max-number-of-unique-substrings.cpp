class Solution {
public:
    unordered_set<string> st;
    int rec(string s, int i, int n, string v)
    {
        if(i>=n) return 0;
        v.push_back(s[i]);
        int excl = 0,incl = 0;
        if(st.find(v) == st.end())
        {
            st.insert(v);
            incl = 1 + rec(s, i+1, n, "");
            st.erase(v);
        }
        excl = rec(s, i+1, n, v);
        return max(incl, excl);
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        return rec(s, 0, n, "");
    }
};
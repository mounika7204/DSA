class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        vector<string> ans;
        string s= "";
        for(int i=0;i<n;i++)
        {
            s += 'a';
            ans.push_back(s);
            while(s.back() != target[i])
            {
                s.back() = (s.back() == 'z') ? 'a' : s.back() + 1;
                ans.push_back(s);
            }
        }
        return ans;
    }
};
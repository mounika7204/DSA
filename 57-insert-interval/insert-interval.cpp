class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans= intervals;
        ans.push_back(newInterval);
        sort(ans.begin(), ans.end());

        vector<vector<int>> res;
        vector<int> prev = ans[0];
        for(int i=0;i<ans.size();i++)
        {
            vector<int> interval = ans[i];
            if(interval[0] <= prev[1])
            {
                prev[1] = max(prev[1], interval[1]);
            }
            else
            {
                res.push_back(prev);
                prev = interval;
            }
        }
        res.push_back(prev);
        return res;
    }
};
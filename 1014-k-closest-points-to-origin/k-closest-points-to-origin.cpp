class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, 
                       greater<pair<int, vector<int>>>> pq;
        for(int i = 0 ; i < n ; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int ans = x*x + y*y;
            pq.push({ans,points[i]});
        }
        vector<vector<int>> result;
        for(int i=0;i<k;i++)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct Compare{
        bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
            return a.first > b.first;
        }
    };
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, Compare> p;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            p.push({matrix[i][0], {i,0}});
        }
        int r = 0;
        for(int i=0;i<k;i++)
        {
            auto pr = p.top();
            p.pop();
            r=pr.first;
            int row = pr.second.first;
            int col = pr.second.second;
            if(col+1<n)
            {
                p.push({matrix[row][col+1], {row,col+1}});
            }
        }
        return r;
    }
};
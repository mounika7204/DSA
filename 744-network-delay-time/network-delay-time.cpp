class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e8);
        dist[k] = 0;
        for(int i=1;i<=n-1;i++)
        {
            for(vector<int> edge: times)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
         for(vector<int> edge: times)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                   return -1;
                }
            }
        int ans = 0;
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i] == 1e8) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
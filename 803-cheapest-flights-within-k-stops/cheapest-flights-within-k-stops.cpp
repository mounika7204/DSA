class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto edge : flights)
        {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            int st = q.front().first;
            int nd = q.front().second.first;
            int ct = q.front().second.second;
            q.pop();
            if(st > k) continue;
            for(auto it: adjList[nd])
            {
                if(st <= k && ct + it.second < price[it.first])
                {
                    price[it.first]=ct+it.second;
                    q.push({st+1,{it.first,ct+it.second}});
                }
            }
        }
        if(price[dst]==INT_MAX)return -1;
        return price[dst];
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adjList(n);
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0, start_node});
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;

        while(!pq.empty())
        {
            double curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == end_node) return curr;
            for(auto n : adjList[node])
            {
                int adjnode = n.first;
                double nprob = n.second;

                if(curr * nprob > prob[adjnode])
                {
                    prob[adjnode] = curr * nprob;
                    pq.push({prob[adjnode], adjnode});
                }
            }
        }
        return 0.0;
    }
};
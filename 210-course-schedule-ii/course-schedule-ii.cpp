class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);
        for(auto edge : prerequisites)
        {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it: adjList[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(result.size() != numCourses)
        {
            return {};
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
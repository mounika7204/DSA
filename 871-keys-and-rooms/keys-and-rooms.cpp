class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> reach(n,0);
        reach[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int room = q.front();
            q.pop();
            reach[room] = 1;
            for(auto nroom : rooms[room])
            {
                if(!reach[nroom])
                    q.push(nroom);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!reach[i]) return false;
        }
        return true;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();
    vector<pair<int,int>> events;
    for(int i=0;i<n;i++)
      {
        events.push_back({times[i][0],i});
        events.push_back({times[i][1] ,-i});
      }
    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> availableChairs;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Occ;
   
    for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
    
    for(auto event : events)
    {
        int time = event.first;
        int friendInx = event.second;

        while(!Occ.empty() && Occ.top().first<=time)
        {
            availableChairs.push(Occ.top().second);
            Occ.pop();
        }

        if(friendInx >= 0)
        {
            int chair = availableChairs.top();
            availableChairs.pop();

            if(friendInx == targetFriend) return chair;

            Occ.push({times[friendInx][1], chair});
        }
    }
    return -1;

    }
};
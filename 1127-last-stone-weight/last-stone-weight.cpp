class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 0) return 0;
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++) pq.push(stones[i]);
        while(!pq.empty() && pq.size() >= 2)
        {
            int firstStone  = pq.top();pq.pop();
            int secondStone = pq.top();pq.pop();
            pq.push(firstStone-secondStone);
        }
        return pq.top();
    }
};
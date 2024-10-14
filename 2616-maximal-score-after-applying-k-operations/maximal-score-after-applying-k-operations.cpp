class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);
        long long score = 0;
        for(int i=0;i<k;i++)
        {
            long long ele = pq.top();
            score += ele;
            pq.pop();
            ele = ceil(static_cast<double>(ele) / 3);
          //  cout<<ele<<endl;
            pq.push(ele);
        }
        return score;
    }
};
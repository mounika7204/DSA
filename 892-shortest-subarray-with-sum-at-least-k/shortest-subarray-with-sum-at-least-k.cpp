class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = n-1;
        int sum = 0;
        long long int len=0,minlen=INT_MAX;
        // for (int left = 0; left < n; ++left) {
        //     long long sum = 0;

        //     for (int right = left; right < n; ++right) {
        //         sum += nums[right];
        //         if (sum >= k) {
        //             minLen = min(minLen, right - left + 1);
        //             break; 
        //         }
        //     }
        // }
        deque<long long int> dq;
        vector<long long int> prefixSum(n+1, 0);
        prefixSum[0]= 0;
        for(int i=0;i<n;i++)
        {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k)
            {
                minlen = min(minlen, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return minlen == INT_MAX ? -1 : minlen;
    }
};
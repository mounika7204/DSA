class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i=0;
        while(i<n)
        {
            long long int cnt = 0;
            if(nums[i] == 0)
            {
                while(i<n && nums[i] == 0)
                {
                    cnt++;
                    i++;
                }
                ans += (cnt*(cnt+1))/2;
            }
            i++;
        }
        return ans;
    }
};
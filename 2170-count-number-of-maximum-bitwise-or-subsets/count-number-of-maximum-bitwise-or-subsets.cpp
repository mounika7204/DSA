class Solution {
public:
    void rec(vector<int> nums, int maxOr, int i, int n, int& cnt, int ele)
    {
        if(i==n)
        {
            if(ele == maxOr)
            {
                cnt++;
            }
            return;
        }
        rec(nums, maxOr, i+1, n, cnt, ele | nums[i]);
        rec(nums, maxOr, i+1, n, cnt, ele);
    }
    int countMaxOrSubsets(vector<int>& nums) {
         int maxOR = 0; 
      for (int i = 0; i < nums.size(); ++i) {
        int currentOR = 0;  
        for (int j = i; j < nums.size(); ++j) {
            currentOR |= nums[j];  
            maxOR = max(maxOR, currentOR); 
        }
    }
    int cnt =0;
    rec(nums, maxOR, 0, nums.size(), cnt, 0);
    return cnt;
    }
};
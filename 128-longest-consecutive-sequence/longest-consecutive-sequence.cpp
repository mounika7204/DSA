class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxlen = 0;

        for(int num : nums)
        {
            if(s.find(num - 1) == s.end())
            {
                int len = 1;
                while(s.find(num+len) != s.end())
                {
                    len++;
                }
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;   
    }
};
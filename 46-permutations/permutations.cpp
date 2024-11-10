class Solution {
public:
    vector<vector<int>> res;
    // Time Complexity : O(n * n!) n! all possible permuatations n - size of nums array
    // Space Complexity : O(n)
    void rec(vector<int> nums, int idx)
    {
        if(idx == nums.size())
        {   
            res.push_back(nums); return;
        }
        for(int i =  idx;i < nums.size();i++)
        {
            swap(nums[i], nums[idx]);
            rec(nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums, 0);
        return res;
    }
};
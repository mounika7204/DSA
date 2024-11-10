class Solution {
public:
     void solve(vector<int> nums,vector<int> output,int i,vector<vector<int>>& ans)
    {
        if(i == nums.size())
        {
            sort(output.begin(), output.end());
            if(find(ans.begin(),ans.end(),output) == ans.end())
            {
                ans.push_back(output);
            }
            return;
        }
        //by excluding values
        solve(nums,output,i+1,ans);

        //by including values
        int ele = nums[i];
        output.push_back(ele);
        solve(nums,output,i+1,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,0,ans);
        return ans;
    }
};
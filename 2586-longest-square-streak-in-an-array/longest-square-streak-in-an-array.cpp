class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
         int max1 = -1;
        unordered_set<int> numSet(nums.begin(), nums.end());
       vector<int> sortedNums(numSet.begin(), numSet.end());
        
        sort(sortedNums.begin(), sortedNums.end());
        
        for (int num : sortedNums) {
            long int curr = num;
            int count = 0;
            
            while (numSet.count(curr)) {
                numSet.erase(curr);
                curr *= curr;
                count++;
            }
            
            max1 = max(max1, count);
        }
        
        return max1 > 1 ? max1 : -1;
    }
};
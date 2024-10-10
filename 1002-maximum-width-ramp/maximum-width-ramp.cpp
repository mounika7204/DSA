class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
    vector<int> indices(n);
    

    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        if (nums[i] == nums[j]) {
            return i < j;  
        }
        return nums[i] < nums[j];
    });

    
    int minv = indices[0];  
    int maxv = 0;

  
    for (int i = 1; i < n; ++i) {
        int current = indices[i];
        maxv = max(maxv, current - minv);
        minv = min(minv, current);
    }

    return maxv;
    }
};
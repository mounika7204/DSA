class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n+1, 0);
        int carry = 1; 

for (int i = n - 1; i >= 0; i--) {
    int num = digits[i] + carry;
    if(num >= 10) carry = (num / 10) % 10;
    else carry = 0;
    ans[i + 1] = num % 10;  
}


if (carry > 0) {
    ans[0] = carry;
} else {
    ans.erase(ans.begin());
}
    return ans;
    }
};
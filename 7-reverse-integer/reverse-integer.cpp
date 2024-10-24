class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0) // x > 0 doesn't pass for negative numbers
        {
            int num = x % 10;
            if((ans > INT_MAX/10) || (ans < INT_MIN/10)) return 0;
            ans = ans * 10 + num;
            x = x / 10;
        }
        return ans;
    }
};
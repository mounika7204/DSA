class Solution {
public:
    string invert(string s)
    {
        string binaryStr = s;
        for (char &ch : binaryStr) {
        if (ch == '1') {
            ch = '0';
        } else if (ch == '0') {
            ch = '1';
        }
         }
         return  binaryStr;
    } 
    char findKthBit(int n, int k) {
        string s = "0";
        vector<string> ans(n);
        ans[0] = "0";
        for(int i=1;i<n;i++)
        {
            string s = invert(ans[i-1]);
            reverse(s.begin(), s.end());
            ans[i] = ans[i-1] + "1" +  s;
        }
        return ans[n-1][k-1];
    }
};
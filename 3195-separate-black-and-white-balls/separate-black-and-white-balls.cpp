class Solution {
public:
    long long minimumSteps(string s) {
        // long long int ans = 0;
        // int n = s.length();
        // int i=0;
        // int j=i+1;
        // while(j<n)
        // {
        //     if(s[i] == '0') 
        //     {
        //         i++;j++;
        //     }
        //     else if(s[i] == '1')
        //     {
        //         if(s[j] == '1')
        //         {
        //             j++;
        //             i++;
        //         }
        //         else
        //         {
        //             swap(s[i],s[j]);
        //         if(i > 0 && j > 0)
        //             {
        //                 i--;
        //                 j--;
        //             }
        //             while(s[i] == '1' && i > 0 && j > 0)
        //             {
        //                 i--;j--;
        //             }
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        long long ans = 0,ones=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '1') ones++;
            else ans += ones;
        }
        return ans;
    }
};
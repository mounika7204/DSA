class Solution {
public:
    int minChanges(string s) {
        int len = s.length();
        int cnt = 0;
        for(int i=0;i<len-1;i+=2)
        {
            if(s[i] != s[i+1]) cnt++;
        }
        return cnt;

    }
};
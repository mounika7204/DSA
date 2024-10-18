class Solution {
public:
    int addMinimum(string word) {
         int i=0, j=0, cnt=0;
        string s = "abc";  
        
        while(i < word.length())    {
            if(word[i] == s[j]) {
                i++;
                j++;
                if(j >= 3)  j = 0;
            }
            else    {
                cnt++;
                j++;
                if(j >= 3)  j = 0;
            }
        }
        if(j==1)    cnt += 2;
        if(j==2)    cnt += 1;
        return cnt;
    }
};
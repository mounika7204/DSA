class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(set.find(endWord) == set.end()) return 0;
        queue<string> q;
        int distance = 1;
        q.push(beginWord);
        while(!q.empty())
        {
            distance++;
            int size = q.size();
            while(size--)
            {
                string currWord = q.front();q.pop();
                for(int i=0;i<currWord.length();i++)
                {
                    string temp = currWord;
                    for(char j ='a' ; j <= 'z' ; j++)
                    {
                        temp[i] = j;
                        if(temp == endWord) return distance;
                        if(set.find(temp) != set.end())
                        {
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
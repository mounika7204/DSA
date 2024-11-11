class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(endGene) == st.end()) return -1;
        queue<string> q;
        q.push(startGene);
        int ans = 0;
        unordered_set<string> visited;
        visited.insert(startGene);
        vector<char> mutations = {'A','C','G','T'};
        while(!q.empty())
        {
            int size = q.size();   
            for(int j=0;j<size;j++)
            {
                string curr = q.front();
                q.pop();
                if(curr == endGene) return ans;
                for(int i=0;i<curr.size();i++)
                {
                char ch = curr[i];
                for(char chr : mutations)
                {
                    if(chr == ch) continue;
                    curr[i] = chr;
                if(st.find(curr) != st.end() && visited.find(curr) == visited.end())
                    {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = ch;
                }
                }
            }
            ++ans;
        }
        return -1;
    }
};
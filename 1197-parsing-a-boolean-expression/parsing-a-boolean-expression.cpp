class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        for(auto ch : expression)
        {

            if(ch == '(' || ch == '&' || ch == '|' || ch == '!' || ch == 'f' || ch=='t') st.push(ch);
            else if(ch == ',') continue;
            else if(ch == ')')
            {
                vector<bool> v;
                while(!st.empty() && st.top() != '(')
                {
                    char t = st.top();
                    st.pop();
                    if(t == 't') v.push_back(true);
                    else v.push_back(false);
                }
                if(!st.empty())
                    st.pop();
                char ex;
                if(!st.empty()) 
                { 
                    ex = st.top();
                    st.pop(); 
                    char c = v[0];
                    if(ex == '&')
                    {
                        for(bool b : v) c &= b;
                    }
                    else if(ex == '|')
                    {
                        for(bool b: v) c |= b;
                    }
                    else
                    {
                        c = !c;
                    }
                    if(c) st.push('t');
                    else st.push('f');
                }
            }

        }
        return st.top()=='t';
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack<char> st;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                // Ensure that the stack is not empty before accessing top element
                if (!st.empty() && st.top() == '(') {
                    st.pop();  // Pop if there's a matching '('
                } else {
                    st.push(s[i]);  // Otherwise, push the ')' since it's unmatched
                }
            }
            i++;
        }
        return st.size();  // The size of the stack will be the minimum number of additions
    }
};
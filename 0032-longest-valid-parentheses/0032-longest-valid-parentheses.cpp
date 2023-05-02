class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }    
                else{
                    st.push(i);
                }
            }
        }
        int res = 0;
        int last = s.size();
        while(!st.empty()){
            int first = st.top();
            st.pop();
            res = max(res, last-first-1);
            last = first;
        }
        return max(last,res);
    }
};
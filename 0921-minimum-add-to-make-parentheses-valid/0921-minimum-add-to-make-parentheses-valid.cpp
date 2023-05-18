class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int cnt = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(st.size() > 0){
                if(ch == '('){
                 st.push(ch);
                }
                else if(ch == ')' && st.top() == '('){
                    st.pop();
                }
                else{
                    cnt++;
                }
            }
            else if(ch == '('  || ch == ')'){
                st.push(ch);
            }
        }
        
        while(st.size() >0){
            cnt++;
            st.pop();
        }
        
        return cnt;
    }
};
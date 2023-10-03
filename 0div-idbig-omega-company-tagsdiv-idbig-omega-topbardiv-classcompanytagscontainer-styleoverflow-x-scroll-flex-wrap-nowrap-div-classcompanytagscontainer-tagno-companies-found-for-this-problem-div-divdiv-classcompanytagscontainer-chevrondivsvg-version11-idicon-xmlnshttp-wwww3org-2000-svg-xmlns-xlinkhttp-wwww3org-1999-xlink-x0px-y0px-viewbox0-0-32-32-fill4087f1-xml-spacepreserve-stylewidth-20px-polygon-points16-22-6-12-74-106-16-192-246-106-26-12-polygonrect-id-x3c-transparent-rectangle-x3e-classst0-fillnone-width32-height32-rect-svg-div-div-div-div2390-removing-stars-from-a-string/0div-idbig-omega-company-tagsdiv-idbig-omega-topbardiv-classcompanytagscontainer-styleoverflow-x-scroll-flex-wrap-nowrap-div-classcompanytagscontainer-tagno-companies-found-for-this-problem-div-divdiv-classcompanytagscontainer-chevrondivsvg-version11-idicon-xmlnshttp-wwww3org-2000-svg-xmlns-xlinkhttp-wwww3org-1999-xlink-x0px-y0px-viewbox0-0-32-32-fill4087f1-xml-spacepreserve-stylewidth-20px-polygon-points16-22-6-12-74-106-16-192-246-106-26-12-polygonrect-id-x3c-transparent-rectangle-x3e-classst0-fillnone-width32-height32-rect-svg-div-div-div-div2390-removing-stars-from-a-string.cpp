class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        
        stack<char> st;
        
        for(int i= 0; i<n; i++){
            if(s[i] != '*'){
                st.push(s[i]);
            }
            if(s[i] == '*'){
                if(st.size() > 0){
                    st.pop();
                }
            }
        }
        
        string ans;
        while(st.size() > 0){
            char ch = st.top();
            ans += ch;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
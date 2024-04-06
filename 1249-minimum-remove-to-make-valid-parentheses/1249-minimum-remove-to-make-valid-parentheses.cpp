class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if (s[i] == ')'){
                
//              if stack is not empty then pop;
                
                if(!st.empty()){
                    st.pop();
                }

//              making the redundant closed bracket as '*'
                
                else{
                    s[i] = '*';
                }
            }
        }
        
        while(!st.empty()){
//          making the redundant open bracket as '*'
            
            s[st.top()] = '*';
            st.pop();
        }
        
        string result = "";
        
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                result += s[i];
            }
        }
        return result;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        
        for(int i=0; i<n; i++){
            if(path[i] =='/'){
                continue;
            }
            string temp;
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if(temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(st.size()>0){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        
        string ans = "";
        if(st.empty())  ans = '/';
        while(st.size()> 0){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
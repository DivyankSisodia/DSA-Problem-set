class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            if(st.size() == 0 || asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

// asteroid - 5 10 -5
//  stack   - 5 10 -5
// ans      - 

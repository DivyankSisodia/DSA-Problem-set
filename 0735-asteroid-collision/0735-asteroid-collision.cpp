// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int> st;
//         for(int i=0; i<asteroids.size(); i++){
//             if(st.size() == 0 || asteroids[i] > 0){
//                 st.push(asteroids[i]);
//             }
//             else{
//                 while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
//                     st.pop();
//                 }
//                 if(!st.empty() && st.top() == abs(asteroids[i])){
//                     st.pop();
//                 }
//                 else if(st.empty() || st.top() < 0){
//                     st.push(asteroids[i]);
//                 }
//             }
//         }
//         vector<int> ans;
//         while(!st.empty()){
//             int top = st.top();
//             st.pop();
//             ans.push_back(top);
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            int flag = 1;
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
                // If the top asteroid in the stack is smaller, then it will explode.
                // Hence pop it from the stack, also continue with the next asteroid in the stack.
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                // If both asteroids are the same size, then both asteroids will explode.
                // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
                else if (abs(st.top()) == abs(asteroid)) {
                    st.pop();
                }

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
                flag = 0;
                break;
            }
            
            if (flag) {
                st.push(asteroid);
            }
        }
        
        // Add the asteroids from the stack to the vector in the reverse order.
        vector<int> remainingAsteroids (st.size());
        for (int i = remainingAsteroids.size() - 1; i >= 0; i--){
            remainingAsteroids[i] = st.top();
            st.pop();
        }
        
        return remainingAsteroids;
    }
};

// asteroid - 5 10 -5
//  stack   - 5 10 -5
// ans      - 

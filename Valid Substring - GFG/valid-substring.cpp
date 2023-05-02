//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<char> st;
        stack<int> idx;
        
        idx.push(-1);
        int len = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                idx.push(i);
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    idx.pop();
                    len = max(len, i-idx.top());
                }
                else{
                    idx.push(i);
                }
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
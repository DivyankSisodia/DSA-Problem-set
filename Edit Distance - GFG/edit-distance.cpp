//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[201][101];
    int solve(string &s, string &t, int i, int j){
        //agar s wali string end ho gyi aur 
        // t wali abhi padi h toh aap add kr dakte ho joh t mein reh gye
        if(i<0){
           return j+1;
        } 
        
        //agar t wali string empty ho gyi toh 
        // s wali se delete operation laga do
        if(j<0){
           return i+1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
           return solve(s,t,i-1,j-1);
        }
        // insert
        int x =  solve(s,t,i,j-1);

        //delete 
        int y =  solve(s,t,i-1,j);
        
        // replace 
        int z =  solve(s,t,i-1,j-1);
        
        return dp[i][j] = 1+ min({x,y,z});
    }
  
    int editDistance(string s, string t) {
        // Code here
        int n = s.size();
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,n-1,m-1);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
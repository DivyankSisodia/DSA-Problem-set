//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int dp[1000001];
  public:
    long long m = 1e9+7;
    long long int helper(int n){
        if(n < 2){
            return n;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return (dp[n] = helper(n-1) + helper(n-2))%m;
    }
    long long int topDown(int n) {
        // code here
        memset(dp,-1,sizeof(dp));
        
        return helper(n);
    }
    long long int bottomUp(int n) {
        // code here
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<n ;i++){
            dp[n] = dp[n-1] + dp[n-2];
        }
        return dp[n]%m;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends
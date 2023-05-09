//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int lcs(string A, string B, int i, int j){
        
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(A[i] == B[j]){
            return 1 + lcs(A,B,i-1,j-1);
        }
        return dp[i][j] = max(lcs(A,B,i-1,j), lcs(A,B,i,j-1));
    }
  
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(B.begin(),B.end());
        int n = A.size();
        int m = B.size();
        memset(dp,-1,sizeof(dp));
        
        return lcs(A,B,n-1,m-1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
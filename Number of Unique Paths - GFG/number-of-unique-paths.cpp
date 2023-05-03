//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int dp[17][17];
    
    int solve(int a, int b){
        if(a == 0 && b == 0){
            return 1;
        }
        if(a<0 || b<0){
            return 0;
        }
        
        if(dp[a][b] != -1){
            return dp[a][b];
        }
        
        int up = solve(a-1, b);
        int left = solve(a,b-1);
        
        return dp[a][b] = up + left;
    }
    
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        return solve(a-1,b-1);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int i, int W, int val[], int wt[]){
        if( i==0 ){
            return (W/wt[i])*val[i];
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int nottake = 0 + solve(i-1,W,val,wt);
        int take = -1e9;
        if(wt[i]<= W){
            take = val[i] + solve(i,W-wt[i],val,wt);
        }
        return dp[i][W] = max(take,nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(N-1,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
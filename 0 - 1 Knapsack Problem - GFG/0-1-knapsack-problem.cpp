//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int helper(int W, int wt[], int val[], int n, int index){
        if(index >= n){
            return 0;
        }
        
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        
        int ans=0;
        if(wt[index] <= W){
            ans = val[index] + helper(W-wt[index],wt,val,n,index+1);
        }
        int notans=0;
        notans = helper(W,wt,val,n,index+1);
        
        return dp[index][W]=max(ans,notans);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return helper(W,wt,val,n,0);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
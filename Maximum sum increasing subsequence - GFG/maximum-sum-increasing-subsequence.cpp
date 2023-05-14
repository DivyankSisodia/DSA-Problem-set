//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001];
	int solve(int arr[], int n, int prev, int i){
	    if(i == n){
	        return 0;
	    }
	    
	    if(dp[i][prev+1] != -1){
	        return dp[i][prev+1];
	    }
	    
	    int pick = 0;
	    if(prev == -1 || arr[i] > arr[prev]){
	        pick = arr[i] + solve(arr,n,i,i+1);
	    }
	    int notPick = solve(arr,n,prev,i+1);
	    
	    return dp[i][prev+1] = max(pick, notPick);
	    
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    return solve(arr,n,-1,0);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends

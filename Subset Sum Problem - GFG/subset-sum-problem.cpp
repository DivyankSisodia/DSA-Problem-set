//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // int dp[101][100001];
    int solve(vector<vector<int>>&dp,vector<int>&arr,int sum,int n)
    {
       if(n==0)
       {  //we have exhausted the array and sum has also reached 0 then we return 1 else we return 0
           if(sum==0) return 1;
           else return 0;
           
       }
       if(dp[n][sum]!= -1) return dp[n][sum];
       
       int pick=0;
       int notPick=0;
       
       
       if(arr[n-1]<=sum)
       {
           pick= solve(dp,arr,sum-arr[n-1],n-1);
       }
       notPick= solve(dp,arr,sum,n-1);
       
       return dp[n][sum]= pick||notPick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        
        int n= arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return solve(dp,arr,sum,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
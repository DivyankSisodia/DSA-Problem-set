//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
//     int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
//     // base condition
//     if(ind == n)
//         return 0;
        
//     if(dp[ind][prev_index+1]!=-1)
//         return dp[ind][prev_index+1];
    
//     int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
//     int take = 0;
    
//     if(prev_index == -1 || arr[ind] > arr[prev_index]){
//         take = 1 + getAns(arr,n,ind+1,ind,dp);
//     }
    
//     return dp[ind][prev_index+1] = max(notTake,take);
// }
//   int longestSubsequence(int n, int arr[])
//   {
//       // your code here
//       vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
//     return getAns(arr,n,0,-1,dp);
//   }


    int longestSubsequence(int n, int arr[])
    { 
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i=1; i<n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            else{
                int x = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[x] = arr[i];
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
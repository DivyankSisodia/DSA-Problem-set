//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int dp[1001][1001];
	
	int lcs(string str1, string str2, int i, int j){
	    
	    if(i < 0 || j < 0){
	        return 0;
	    }
	    
	    if(dp[i][j] != -1){
	        return dp[i][j];
	    }
	    
	    if(str1[i] == str2[j]){
	        return 1 + lcs(str1,str2,i-1,j-1);
	    }
	    return dp[i][j] = max(lcs(str1,str2,i-1,j), lcs(str1,str2,i,j-1));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    int n = str1.size();
	    int m = str2.size();
	    int x = lcs(str1,str2,n-1,m-1);
	    return (n-x) + (m-x);  
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
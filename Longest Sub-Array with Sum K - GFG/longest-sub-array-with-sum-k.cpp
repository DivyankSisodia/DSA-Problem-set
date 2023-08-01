//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        // Complete the function
        int sum = 0;
        int len = 0;
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            sum = sum + A[i];
            if(sum == k){
                len = max(len, i+1);
            }
            int remaining = sum - k;
            if(mp.find(remaining) != mp.end()){
                int remlen = i - mp[remaining];
                len = max(len , remlen);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
        return len;
    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
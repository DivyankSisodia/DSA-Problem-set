//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int socc(int arr[], int n, int x){
        int s = 0;
        int e = n-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] == x){
                ans = mid;
                s = mid+1;
            }
            else if(arr[mid] < x){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
		
    int focc(int arr[], int n, int x){
        int s = 0;
        int e = n-1;
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid] == x){
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid] < x){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
		
	int count(int arr[], int n, int x) {
	    // code here
	    int first = focc(arr,n,x);
	    if(first == -1){
	        return 0;
	    }
	    
	    int second = socc(arr,n,x);
	    return second - first + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
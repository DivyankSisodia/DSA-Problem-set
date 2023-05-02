//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[100001];
    int helper(int n, vector<int> &height, int k){
        if(n == 0){
            return 0;
        }
        int step = INT_MAX;
        if(dp[n] != -1){
            return dp[n];
        }
        for(int i=1; i<=k; i++){
            if(n-i >= 0){
                int jump = helper(n-i, height, k) + abs(height[n] - height[n-i]);
                step = min(step,jump);
            }
        }
        return dp[n] = step;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        memset(dp,-1,sizeof(dp));
        return helper(n-1,height,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
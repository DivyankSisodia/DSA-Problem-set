//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int solve(int i,int j, vector<vector<int>>& v){
        int n = v.size();
        if(i == n-1){
            return v[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = v[i][j] + solve(i+1,j,v);
        int diagonal = v[i][j] + solve(i+1,j+1,v);
        
        return dp[i][j] = min(down,diagonal);
    }
  
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(0,0, triangle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends
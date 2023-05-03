//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[71][101][101];
    int helper(int i, int alex, int bob, int n, int m, vector<vector<int>>& grid){
        //boundary cases
        if(alex<0 || alex>=m || bob<0 || bob>=m){
            return -1e8;
        }
        if(i == n-1){
            if(alex == bob){
                return grid[i][alex];
            }
            else{
                return grid[i][alex] + grid[i][bob];
            }
        }
        
        if(dp[i][alex][bob] != -1){
            return dp[i][alex][bob];
        }
        
        int maxi = 0;
        // movements in grid according to alex and bob
        
        for(int d= -1; d <= 1; d++){
            for(int d2 = -1; d2<= 1; d2++){
                int value = 0;
                
                if(alex == bob){
                    value = grid[i][alex];
                }
                else{
                    value = grid[i][alex] + grid[i][bob];
                }
                
                value = value + helper(i+1, alex+d, bob+d2,n,m,grid);
                
                maxi = max(maxi,value);
            }
        }
        return dp[i][alex][bob] = maxi;
    }
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        memset(dp,-1,sizeof(dp));
        return helper(0,0,m-1,n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
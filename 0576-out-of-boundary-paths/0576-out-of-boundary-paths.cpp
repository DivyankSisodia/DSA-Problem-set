class Solution {
public:
    int dp[52][51][51];
    int mod = 1000000007;
    int solve(int m, int n, int X, int i, int j){
        if(i <0 || j<0 || i == m || j == n){
            return 1;
        }
        if(X == 0){
            return 0;
        }
        if(dp[X][i][j] != -1){
            return dp[X][i][j];
        }
        int ans = 0;
        ans = (ans +  solve(m,n,X-1,i,j+1))%mod;
        ans = (ans +  solve(m,n,X-1,i,j-1))%mod;
        ans = (ans +  solve(m,n,X-1,i+1,j))%mod;
        ans = (ans +  solve(m,n,X-1,i-1,j))%mod;
        
        return dp[X][i][j] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        // vector<vector<int>> dp(maxMove+1, vector<int>(startRow+1))
        return solve(m,n,maxMove,startRow,startColumn)%mod;
    }
};
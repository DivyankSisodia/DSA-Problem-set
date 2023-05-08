class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int m, int n){
        if(i == 0 &&  j == 0){
            return 1;
        }
        if( i<0 || j<0 || i>m || j>n){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = solve(i-1,j,m,n);
        int left = solve(i,j-1,m,n);
        
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,m,n);
    }
};
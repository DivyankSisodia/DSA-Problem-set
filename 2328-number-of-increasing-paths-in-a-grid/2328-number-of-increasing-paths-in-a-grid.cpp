class Solution {
public:
    int mod = 1e9 + 7;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    
    int solve(int row, int col, int n ,int m, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int res = 1;
        
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && grid[row][col] < grid[nrow][ncol])
            {
                res += solve(nrow, ncol, n, m, grid,dp);
            }
        }
        return dp[row][col] = res% mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        long long ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += solve(i,j,n,m,grid,dp);
            }
        }
        
        return ans%mod;
    }
};
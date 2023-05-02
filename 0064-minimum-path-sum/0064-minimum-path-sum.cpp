class Solution {
public:
    
    int dp[1001][1001];
    
    int solve(vector<vector<int>>& grid, int i, int j){
        
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        
        if(i<0 || j<0){
            return 1e9;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        long up = grid[i][j] + solve(grid,i-1,j);
        long left = grid[i][j] + solve(grid,i,j-1);
        
        return dp[i][j] = min(up,left);
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid, n-1, m-1);
    }
};
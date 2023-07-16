class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>&grid, int n, int m){
        
        if(row<0 && row >= n && col <0 && col>=m && grid[row][col] == 1){
            return;
        }
//         most important line is grid[row][col] = 1;
        grid[row][col] = 1;
        
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        
        for(int i=0; i<4; i++){
            int r = row + drow[i];
            int c = col + dcol[i];
            
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 0){
                dfs(r,c,grid,n,m);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 0){
                dfs(i,0,grid,n,m);
            }
            if(grid[i][m-1] == 0){
                dfs(i,m-1,grid,n,m);
            }
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j] == 0){
                dfs(0,j,grid,n,m);
            }
            if(grid[n-1][j] == 0){
                dfs(n-1,j,grid,n,m);
            }
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return ans;
    }
};
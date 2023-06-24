class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        // queue<pair<int,int>> q;
        int delrow[] = {0,1,0,-1};
        int delcol[] = {-1,0,1,0};
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1 && vis[0][j] != 1){
                dfs(0, j, vis,grid, delrow, delcol);
            }
            if(grid[n-1][j] == 1 && vis[n-1][j] != 1){
                dfs(n-1, j, vis , grid, delrow, delcol);
            }
        }
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && vis[i][0] != 1){
                dfs(i, 0, vis, grid, delrow, delcol);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] != 1){
                dfs(i, m-1, vis, grid, delrow, delcol);
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1)cnt++;//counting the number of 1s that are visited from the boundary
            }
        }
        // int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)ans++;//counting the number of ones int the matrix
            }
        }
        return ans-cnt;
    }
};
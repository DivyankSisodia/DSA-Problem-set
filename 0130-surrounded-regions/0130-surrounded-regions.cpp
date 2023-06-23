class Solution {
public:
    
    //                              DFS SOLUTION H LOLE
    
//     void dfs(int row, int col, vector<vector<int>>&grid, int n, int m,
//              vector<vector<int>>&vis, int delrow[], int delcol[]){
        
//         vis[row][col] = 1;
        
//         for(int i=0; i<4; i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
            
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 'O'){
//                 dfs(nrow, ncol, grid, n, m, vis, delrow, delcol);
//             }
//         }
//     }
    
//     void solve(vector<vector<char>>& grid) {
        
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<int>> vis(n, vector<int>(m, 0));
        
//         int delrow[] = {0, -1, 0, 1};
//         int delcol[] = {1, 0, -1, 0};
        
//         // traverse first row and last row
//         for(int j=0; j<m; j++){
//             if(grid[0][j] == 'O' && vis[0][j] == 0){
//                 dfs(0, j, grid, n, m ,vis, delrow, delcol);
//             }
//             if(grid[n-1][j] == 'O' && vis[n-1][j] == 0){
//                 dfs(n-1, j, grid, n, m, vis, delrow, delcol);
//             }
//         }
        
//         // traverse for columns
        
//         for(int i=0; i<n; i++){
//             if(grid[i][0] == 'O' && vis[i][0] == 0){
//                 dfs(i, 0, grid, n, m, vis, delrow, delcol);
//             }
            
//             if(grid[i][m-1] == 'O' && vis[i][m-1] == 0){
//                 dfs(i, m-1, grid, n, m, vis, delrow, delcol);
//             }
//         }
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(vis[i][j] == 0 && grid[i][j] == 'O'){
//                     grid[i][j] = 'X';
//                 }
//             }
//         }
//     }
    
    
    // bfs
    
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> temp = grid;
        
        for(int i=0;i<m;i++){
            
            if(temp[i][0] == 'O')
                bfs1(i,0,temp,grid);
            
            if(temp[i][n-1] == 'O')
                bfs1(i,n-1,temp,grid);
        }
        for(int i=0;i<n;i++){
            
            if(temp[0][i] == 'O')
                bfs1(0,i,temp,grid);
            
            if(temp[m-1][i] == 'O')
                bfs1(m-1,i,temp,grid);
            
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j] == 'O'){
                    temp[i][j] = 'X';
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j] == '1')
                    temp[i][j] = 'O';
            }
        }
        grid = temp;
    }
    
    void bfs1(int i, int j, vector<vector<char>>& vis,vector<vector<char>> grid){
        
        int m = grid.size();
        int n = grid[0].size();
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        
        q.push({i,j});
        vis[i][j] = '1';
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            
            for(int k=0;k<4;k++){
                int nrow = row + drows[k];
                int ncol = col + dcols[k];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 'O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = '1';
                }
            }
        }
    }
};
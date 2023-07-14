class Solution {
public:
    vector<int> x = {+1, -1, 0, 0};
    vector<int> y = {0, 0, +1, -1};
    
//     void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
//         if(i >=0 && i<n && j>=0 && j<m && grid[i][j] == '1'){
//             grid[i][j] = '2';
//         }
        
//         for(int k=0; k<4; k++){
//             int nrow = i + row[k];
//             int ncol = j + col[k];
//             dfs(grid, nrow, ncol, n, m);
//         }
//     }
    void helper(vector<vector<char>> &grid, int i, int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == '1'){
            grid[i][j] = '2';
            
            for(int k=0; k<4; k++){
                int newR = i+x[k];
                int newC = j+y[k];
                helper(grid, newR, newC);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    helper(grid,i,j);
                }
            }
        }
        return ans;
    }
};
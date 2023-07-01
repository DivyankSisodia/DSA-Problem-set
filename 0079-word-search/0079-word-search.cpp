class Solution {
public:
    bool solve(vector<vector<char>>& grid, string word, int i, int j, int ws, int n, int m){
        
        if(word.size() == ws){
            return true;
        }
        
        if(i<0 || j<0){
            return false;
        }
        if(i >= n || j>= m){
            return false;
        }
        
        if(grid[i][j]!=word[ws]){
            return false;
        }
        
        char ch = grid[i][j];
        
        grid[i][j] = '#';
        
        bool up = solve(grid,word,i-1,j,ws+1,n,m);
        bool down = solve(grid, word, i+1, j, ws+1, n ,m);
        bool left = solve(grid, word, i, j-1,ws+1, n, m);
        bool right = solve(grid, word, i, j+1, ws+1, n, m);
        
        grid[i][j] = ch;
        
        return up || down || left || right;
        
    }
    
    bool exist(vector<vector<char>>& grid, string word) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(grid,word,i,j,0,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
};
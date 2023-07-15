class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        int time = 0;
//         pair cause need to store co-ordinates
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {-1,0,1,0};
        
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow >=0 && ncol >=0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        freshOranges--;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty()){
                time++;
            }
        }
        if(freshOranges == 0){
            return time;
        }
        return -1;
    }
};
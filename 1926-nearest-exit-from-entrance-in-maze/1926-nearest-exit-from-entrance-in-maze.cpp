class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        int step = 0;
        
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        
        vector<vector<int>> vis(n ,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        
        vis[entrance[0]][entrance[1]] = 1;
        
        while(!q.empty()){
            int size = q.size();
            step++;
            for(int j=0; j<size; j++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nr = x + dr[i];
                    int nc = y + dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc] != '+' && !vis[nr][nc]){
                        if(nr == 0 || nc == 0 || nr == n-1 || nc == m-1){
                            return step;
                        }
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

// nt m = maze.size(), n = maze[0].size(), steps = 0;
//         vector<int> v(n, 0);
//         vector<vector<int>> visited(m, v);
//         queue<pair<int, int>> q;

//         int r[4] = {0, 0, -1, 1};
//         int c[4] = {1, -1, 0, 0};

//         q.push({entrance[0], entrance[1]});
//         visited[entrance[0]][entrance[1]] = 1;

//         while(!q.empty()) {
//             int size = q.size();
//             steps++;

//             for(int j = 0; j < size; j++) {
//                 auto node = q.front(); q.pop();

//                 for(int i = 0; i < 4; i++) {
//                     int row = r[i] + node.first;
//                     int col = c[i] + node.second;

//                     if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && maze[row][col] == '.') {
//                         if((row == 0 || col == 0 || row == m - 1 || col == n - 1)) return steps;
//                         visited[row][col] = 1;
//                         q.push({row, col});
//                     }
//                 }
//             }
//         }
//         return -1;
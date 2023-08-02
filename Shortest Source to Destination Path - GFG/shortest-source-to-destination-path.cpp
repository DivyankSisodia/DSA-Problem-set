//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y) {
        // code here
        
        if(X == 0 && Y == 0){
            return 0;
        }
        if(grid[0][0]==0) return -1;
        
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({0, {0,0}});
        
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr<n && nr>=0 && nc>=0 && nc<m && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
                    dist[nr][nc] = dis + 1;
                    
                    if(nr == X && nc == Y){
                        return dis+1;
                    }
                
                    q.push({1+dis, {nr,nc}});
                }
            }
        }
        return -1;
        
        // int dr[4] = {0,1,0,-1};
        // int dc[4] = {1,0,-1,0};
        
        // while(!q.empty()){
        //     auto it = q.front();
        //     q.pop();
        //     int dis = it.first;
        //     int r = it.second.first;
        //     int c = it.second.second;
            
        //     for(int i=0; i<4; i++){
        //         int nr = r + dr[i];
        //         int nc = c + dc[i];
                
        //         if(nr<n && nr>=0 && nc>=0 && nc<m && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
        //             dist[nr][nc] = 1 + dis;
        //             if(nr == X && nc == Y){
        //                 return dis;
        //             }
        //             q.push({1+dis, {nr,nc}});
        //         }
        //     }
        // }
        // return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
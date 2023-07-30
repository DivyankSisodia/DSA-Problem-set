class Solution {
public:
    
    void solve(int curr, vector<vector<int>>& rooms, vector<int>&vis){
        vis[curr] = 1;
        
        for(auto it: rooms[curr]){
            if(vis[it] != 1){
                solve(it, rooms, vis);
            }
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        
        solve(0 ,rooms,vis);
        
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == false){
                return false;
            }
        }
        return true;
    }
};
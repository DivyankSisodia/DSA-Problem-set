class Solution {
public:
    
    void dfs(int curr, vector<vector<int>>& isConnected, vector<int>&vis){
        vis[curr] = 1;
        for(int i=0; i<isConnected.size(); i++){
            if(curr!=i && vis[i] == 0 && isConnected[curr][i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        int ans = 0;
        vector<int> vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};
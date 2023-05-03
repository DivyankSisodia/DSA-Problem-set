class Solution {
public:
    
    int solve(int i, int j, int n, vector<vector<int>>& v,vector<vector<int>> &dp){
       if(j<0 || j>n-1)
            return 1e9;
        
        if(i==0)
            return v[i][j];
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = v[i][j] + solve(i-1,j,n,v,dp);
        int ld = v[i][j] + solve(i-1,j+1,n,v,dp);
        int rd = v[i][j] + solve(i-1,j-1,n,v,dp);
        
        return dp[i][j] = min(up, min(ld, rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& v) {
        
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            int x = solve(n-1,j,n,v,dp);
            ans = min(ans,x);
        }
        return ans;
    }
};
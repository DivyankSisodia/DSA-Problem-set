class Solution {
public:
    int dp[201][201];
    int solve(int i, int j,int n, vector<vector<int>>& v){
        if(i == n-1){
            return v[n-1][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = v[i][j]+solve(i+1,j,n,v);
        int diag = v[i][j]+solve(i+1,j+1,n,v);
        
        return dp[i][j] = min(down,diag);
    }
    
    int minimumTotal(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        int n = v.size();
        int m = v[0].size();
        return solve(0,0,n,v);
    }
};
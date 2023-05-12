class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& v1, vector<int>& v2, int i, int j){
        if(i <0 || j<0){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(v1[i] == v2[j]){
            return dp[i][j] = 1 + solve(v1,v2,i-1,j-1);
        }
        else{
            return dp[i][j] = max(solve(v1,v2,i-1,j), solve(v1,v2,i,j-1));
        }
        return 0;
    }
    
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();
        memset(dp,-1,sizeof(dp));
        return solve(v1,v2,n-1,m-1);
    }
};
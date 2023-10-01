class Solution {
public:
    int dp[1001][1001];
    int solve(string &text1, string &text2, int n, int m, int i, int j){
        if(i == n || j == m){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(text1, text2, n, m, i+1, j+1);
        }
        else
            return dp[i][j] = max(solve(text1, text2,n,m,i+1,j), solve(text1,text2,n,m,i,j+1));
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = text1.size();
        int m = text2.size();
        return solve(text1,text2,n,m,0,0);
    }
};
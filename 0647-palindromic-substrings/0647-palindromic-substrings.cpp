class Solution {
public:
    int dp[1001][1001];
    int isPal(string s, int n, int i ,int j){
        if(i>=j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]!=s[j]){
            return dp[i][j] = 0;
        }
        return dp[i][j] = isPal(s,n,i+1,j-1);
    }
    
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n ;i++){
            for(int j=i; j<n; j++){
                if(isPal(s,n,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
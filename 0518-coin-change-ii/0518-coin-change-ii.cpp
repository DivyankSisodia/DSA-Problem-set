class Solution {
public:
    int dp[301][5001];
    int solve(int amount, vector<int>& coins, int i){
        
        if(i ==0){
            return (amount%coins[i] == 0);
        }
        
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int pick = 0;
        if(coins[i]<=amount){
            pick = solve(amount-coins[i],coins,i);
        }
        int notpick = solve(amount,coins,i-1);
        
        return dp[i][amount] = pick+notpick;
        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
        return solve(amount, coins, n-1);
    }
};
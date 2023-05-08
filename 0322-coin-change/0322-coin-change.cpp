class Solution {
public:
    int coinChange(vector<int> &coins, int amount) 
    {
        int dp[13][10001];
        for(int am=0; am<=amount; am++)
            dp[0][am] = am%coins[0]==0 ? am/coins[0] : 1e9;
        for(int cur=1; cur<coins.size(); cur++)
        {
            for(int am=0; am<=amount; am++)
            {
                int doNotTakeCoin = 0 + dp[cur-1][am];
                int takeCoin = INT_MAX;
                if(coins[cur] <= am) 
                    takeCoin = 1 + dp[cur][am-coins[cur]];
                dp[cur][am] = min(takeCoin, doNotTakeCoin);
            }
        }
        return (dp[coins.size()-1][amount] >= 1e9) ? -1 : dp[coins.size()-1][amount];
    }
};
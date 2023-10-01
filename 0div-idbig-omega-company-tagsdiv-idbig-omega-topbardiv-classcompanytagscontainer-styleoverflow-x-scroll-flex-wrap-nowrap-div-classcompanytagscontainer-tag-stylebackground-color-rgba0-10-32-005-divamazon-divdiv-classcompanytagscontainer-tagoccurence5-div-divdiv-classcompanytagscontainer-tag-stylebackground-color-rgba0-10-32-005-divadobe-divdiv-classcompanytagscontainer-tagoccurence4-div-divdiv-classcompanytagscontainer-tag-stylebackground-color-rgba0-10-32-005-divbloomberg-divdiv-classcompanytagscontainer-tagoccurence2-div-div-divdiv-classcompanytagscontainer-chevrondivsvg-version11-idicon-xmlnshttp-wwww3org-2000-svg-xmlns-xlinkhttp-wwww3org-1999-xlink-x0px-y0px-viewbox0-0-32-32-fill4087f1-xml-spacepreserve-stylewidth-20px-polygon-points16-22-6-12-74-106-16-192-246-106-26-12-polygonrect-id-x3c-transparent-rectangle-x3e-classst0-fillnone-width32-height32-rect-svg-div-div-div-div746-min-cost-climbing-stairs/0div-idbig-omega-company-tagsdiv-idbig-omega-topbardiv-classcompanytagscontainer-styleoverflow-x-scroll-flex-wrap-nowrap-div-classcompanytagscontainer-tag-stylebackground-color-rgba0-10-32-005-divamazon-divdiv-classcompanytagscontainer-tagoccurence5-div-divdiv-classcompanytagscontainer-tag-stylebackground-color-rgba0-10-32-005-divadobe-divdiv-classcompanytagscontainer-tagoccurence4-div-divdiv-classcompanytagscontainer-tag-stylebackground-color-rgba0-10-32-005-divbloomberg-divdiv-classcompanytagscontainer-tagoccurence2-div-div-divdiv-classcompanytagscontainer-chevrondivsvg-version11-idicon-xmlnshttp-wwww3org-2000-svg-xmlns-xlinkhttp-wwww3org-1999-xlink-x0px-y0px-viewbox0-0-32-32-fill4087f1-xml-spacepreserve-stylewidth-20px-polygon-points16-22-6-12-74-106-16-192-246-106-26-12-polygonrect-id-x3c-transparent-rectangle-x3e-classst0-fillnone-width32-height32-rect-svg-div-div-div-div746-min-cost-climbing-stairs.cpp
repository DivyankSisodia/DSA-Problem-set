class Solution {
public:
    
    int dp[1001];
    int solve(int n, vector<int> &cost){
        
        if(n <= 1){
            return dp[n] = cost[n];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int pick = solve(n-1, cost);
        int nonpick = solve(n-2, cost);
        
        return dp[n] = cost[n] + min(pick, nonpick);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return min(solve(n-1,cost), solve(n-2,cost));
    }
};
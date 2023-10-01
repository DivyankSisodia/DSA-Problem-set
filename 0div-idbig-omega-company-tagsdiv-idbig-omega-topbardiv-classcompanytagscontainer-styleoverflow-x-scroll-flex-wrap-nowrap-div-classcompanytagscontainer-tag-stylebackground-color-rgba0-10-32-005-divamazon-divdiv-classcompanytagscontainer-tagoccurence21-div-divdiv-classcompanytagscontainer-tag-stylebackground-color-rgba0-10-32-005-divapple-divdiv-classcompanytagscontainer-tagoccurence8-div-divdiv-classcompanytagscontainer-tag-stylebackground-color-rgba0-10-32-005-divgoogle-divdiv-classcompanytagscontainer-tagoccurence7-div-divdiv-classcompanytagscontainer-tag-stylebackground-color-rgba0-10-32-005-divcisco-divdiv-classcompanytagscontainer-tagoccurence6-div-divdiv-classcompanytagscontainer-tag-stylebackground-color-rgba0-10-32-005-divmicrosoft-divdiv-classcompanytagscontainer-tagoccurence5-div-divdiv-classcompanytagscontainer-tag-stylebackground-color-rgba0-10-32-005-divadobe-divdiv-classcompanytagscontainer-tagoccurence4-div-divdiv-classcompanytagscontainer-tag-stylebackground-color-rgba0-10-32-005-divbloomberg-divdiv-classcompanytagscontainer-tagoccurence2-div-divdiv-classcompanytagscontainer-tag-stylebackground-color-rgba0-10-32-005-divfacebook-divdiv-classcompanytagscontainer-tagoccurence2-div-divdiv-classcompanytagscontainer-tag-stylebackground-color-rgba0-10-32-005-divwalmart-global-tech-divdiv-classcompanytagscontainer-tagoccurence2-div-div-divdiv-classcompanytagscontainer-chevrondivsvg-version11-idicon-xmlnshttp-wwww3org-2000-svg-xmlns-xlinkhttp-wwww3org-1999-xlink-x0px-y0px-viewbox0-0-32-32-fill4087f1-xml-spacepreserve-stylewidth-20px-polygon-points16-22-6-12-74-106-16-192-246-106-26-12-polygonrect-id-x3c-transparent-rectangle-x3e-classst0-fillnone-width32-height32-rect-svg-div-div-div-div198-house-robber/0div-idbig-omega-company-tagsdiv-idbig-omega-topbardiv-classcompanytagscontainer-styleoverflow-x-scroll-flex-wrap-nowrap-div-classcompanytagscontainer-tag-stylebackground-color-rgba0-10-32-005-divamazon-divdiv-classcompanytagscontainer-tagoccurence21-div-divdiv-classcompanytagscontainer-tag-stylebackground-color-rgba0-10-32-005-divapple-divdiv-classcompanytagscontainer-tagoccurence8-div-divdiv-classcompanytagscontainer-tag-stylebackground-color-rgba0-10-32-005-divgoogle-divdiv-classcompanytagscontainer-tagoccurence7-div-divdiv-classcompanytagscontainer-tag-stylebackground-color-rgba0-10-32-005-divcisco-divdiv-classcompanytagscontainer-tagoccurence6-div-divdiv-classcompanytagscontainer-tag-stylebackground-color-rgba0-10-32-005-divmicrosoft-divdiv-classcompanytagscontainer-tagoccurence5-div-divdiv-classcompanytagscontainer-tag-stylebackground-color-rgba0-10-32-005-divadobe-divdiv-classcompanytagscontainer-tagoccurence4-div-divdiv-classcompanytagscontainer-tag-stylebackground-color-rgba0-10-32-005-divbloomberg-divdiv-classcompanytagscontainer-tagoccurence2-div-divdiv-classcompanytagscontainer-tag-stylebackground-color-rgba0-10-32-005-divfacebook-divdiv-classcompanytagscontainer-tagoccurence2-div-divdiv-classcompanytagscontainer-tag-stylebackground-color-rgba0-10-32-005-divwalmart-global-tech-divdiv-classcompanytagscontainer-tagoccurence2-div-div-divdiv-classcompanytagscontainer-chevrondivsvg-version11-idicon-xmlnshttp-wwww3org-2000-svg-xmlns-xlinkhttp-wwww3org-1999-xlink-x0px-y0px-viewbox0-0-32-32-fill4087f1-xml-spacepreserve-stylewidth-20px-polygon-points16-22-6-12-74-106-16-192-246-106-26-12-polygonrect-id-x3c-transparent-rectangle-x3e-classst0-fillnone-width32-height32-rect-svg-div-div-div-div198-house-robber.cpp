class Solution {
public:
    int dp[101];
    int solve(vector<int>&nums, int n, int i){
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int Robbery = nums[i] + solve(nums,n,i+2);
        int nonRobbery = solve(nums,n,i+1);
        
        return dp[i] = max(Robbery, nonRobbery);
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,n,0);
    }
};
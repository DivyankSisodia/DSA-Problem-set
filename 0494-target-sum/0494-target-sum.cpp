class Solution {
public:
    int dp[21][2001];
    int solve(int i, vector<int>&nums, int target, int sum){
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[i][sum+1000]!= -1){
            return dp[i][sum+1000];
        }
        
        int cunt = 0;
        
        cunt = cunt + solve(i+1,nums,target,sum+nums[i]);
        cunt = cunt + solve(i+1,nums,target,sum-nums[i]);
        
        return cunt;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target,0);
    }
};
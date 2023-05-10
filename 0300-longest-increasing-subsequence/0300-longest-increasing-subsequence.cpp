class Solution {
public:
    
    int solve(vector<int>&nums,int n, int idx, int pre,vector<vector<int>>&dp){
        if(idx == n){
            return 0;
        }
        if(dp[idx][pre+1] != -1){
            return dp[idx][pre+1];
        }
        int notTake = solve(nums,n,idx+1,pre,dp);
        int take = 0;
        if(pre == -1 || nums[idx] > nums[pre]){
            take = 1 + solve(nums,n,idx+1,idx,dp);
        }
        return dp[idx][pre+1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return solve(nums,n,0,-1,dp);
    }
};
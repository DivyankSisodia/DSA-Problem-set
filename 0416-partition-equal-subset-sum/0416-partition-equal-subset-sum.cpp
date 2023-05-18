class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>&nums, int n ,int i, int target){
        
        if(target==0)
            return true;
    
        if(i == 0)
            return nums[0] == target;
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int pick = 0;
        int notPick = 0;
        if(target >= nums[i]){
            pick = solve(nums,n,i-1,target-nums[i]);
        }
        notPick = solve(nums,n,i-1,target);
        
        return dp[i][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        return solve(nums,n,n-1,sum/2);
    }
};
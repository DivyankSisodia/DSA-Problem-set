class Solution {
public:
    int dp[21][2001];
    int solve(vector<int>&nums, int target, int n,int sum, int i){
        if(i == n){
            if(sum == target){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+1000] != -1){
            return dp[i][sum+1000];
        }
        int cnt = 0;
        cnt += solve(nums,target, n,sum + nums[i], i+1);
        cnt += solve(nums,target,n,sum - nums[i], i+1);
        
        return cnt;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums, target, n,0, 0);
    }
};
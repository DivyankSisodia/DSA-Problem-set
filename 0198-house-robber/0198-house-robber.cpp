class Solution {
public:
    
    int dp[1001];
    
    int helper(vector<int>& nums, int index){
        if(index >= nums.size()){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int rob = nums[index] + helper(nums, index + 2);
        int notRob = helper(nums, index + 1);
        
        return dp[index] = max(rob, notRob);
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0);
    }
};
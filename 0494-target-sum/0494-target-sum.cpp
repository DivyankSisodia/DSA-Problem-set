class Solution {
public:
    int solve(int i, vector<int>&nums, int target, int sum){
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }
            else{
                return 0;
            }
        }
        int cunt = 0;
        
        cunt = cunt + solve(i+1,nums,target,sum+nums[i]);
        cunt = cunt + solve(i+1,nums,target,sum-nums[i]);
        
        return cunt;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0,nums,target,0);
    }
};
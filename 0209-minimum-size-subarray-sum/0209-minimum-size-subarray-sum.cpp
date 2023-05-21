class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            while(sum >= target){
                ans = min(ans, i-left+1);
                sum = sum - nums[left];
                left++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};
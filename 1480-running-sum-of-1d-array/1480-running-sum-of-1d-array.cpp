class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int sum = nums[0];
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++){
            sum = sum + nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
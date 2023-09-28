class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int res = abs(nums[i]) - 1;
            
            nums[res] *= -1;
            
            if(nums[res] > 0){
                ans.push_back(res+1);
            }
        }
        return ans;
    }
};
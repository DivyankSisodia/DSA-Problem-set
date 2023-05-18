class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int l = n-1;
        vector<int> ans;
        
        while(s<=l){
            if(abs(nums[s]) > abs(nums[l])){
                ans.push_back(nums[s]*nums[s]);
                s++;
            }
            else{
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int n = nums.size();
        int product = 1;
        int ans = 0;
        int left = 0;
        
        for(int right = 0; right<n; right++){
            product = product * nums[right];
            while(product >= k){
                product = product / nums[left];
                left++;
            }
            ans = ans + (right-left+1);
        }
        return ans;
    }
};
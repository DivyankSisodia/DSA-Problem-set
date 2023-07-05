class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size();
        long long right = 0;
        long long left = 0;
        long long count = 0;
        long long prod = 0;
        long long sum = 0;
        
        for(right = 0; right<n; right++){
            sum = sum + nums[right];
            prod = sum * (right - left + 1);
            
            while(prod >= k && left <= right){
                sum = sum - nums[left];
                left++;
                prod = sum * (right - left +1);
            }
            if(prod < k){
                count = count + (right-left+1);
            }
        }
        return count;
    }
};
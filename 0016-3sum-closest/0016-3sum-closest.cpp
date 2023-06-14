class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n-2; i++){
            int j = i+ 1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return target;
                }
                
                if(abs(target - sum) < diff){
                    diff = abs(target - sum);
                    ans = sum;
                }
                
                else if(sum > target){
                    k--;
                }
                else
                {
                    j++;
                }
                
            }
            
        }
        return ans;
    }
};
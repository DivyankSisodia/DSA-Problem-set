class Solution {
public:
    
    int totalSum(vector<int>& nums, int n){
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        return sum;
    }
    
    int maxElement(vector<int>& nums, int n){
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        return maxi;
    }
    
    int helperFunc(int x, vector<int>& nums, int n){
        int partitions = 1;
        int sum = 0;
        
        for(int i=0; i<n; i++){
            if(sum + nums[i] <= x){
                sum += nums[i];
            }
            else{
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = maxElement(nums, n);
        int high = totalSum(nums, n);
        
        while(low <= high){
            int mid = (low + high)/2;
            if(helperFunc(mid, nums, n) <= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
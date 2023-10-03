class Solution {
public:
    int m = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1; 
        int ans = 0;
        
        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++){
            power[i] = (power[i-1] * 2) % m; 
        }
        
        while(i<=j){
            if(nums[i] + nums[j] <= target){
                ans = (ans + power[j-i]) % m;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
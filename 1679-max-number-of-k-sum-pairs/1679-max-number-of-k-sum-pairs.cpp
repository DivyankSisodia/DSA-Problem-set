class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        
        sort(nums.begin(), nums.end());
        int cnt = 0;
        
        while(i<j){
            if(nums[i] + nums[j] == k){
                cnt++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return cnt;
        
    }
};
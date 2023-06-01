class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(sum == k){
                cnt++;
            }
            if(mp.find(sum- k) != mp.end()){
                cnt = cnt + mp[sum-k];
            }
            
            mp[sum]++;
            
        }
        return cnt;
    }
};
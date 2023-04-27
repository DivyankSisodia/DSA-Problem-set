class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int cnt = 0;
        for(int i=0 ;i<nums.size(); i++){
            sum = sum + nums[i];
            if(sum == k){
                cnt++;
            }
            if(mp.find(sum-k) != mp.end()){
                cnt = cnt + mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
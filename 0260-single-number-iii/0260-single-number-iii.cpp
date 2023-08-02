class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mp;
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(mp[nums[i]] == 1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map <int,int> mp;
        for(int i=0;i<=nums.size();i++)
            mp[i]=0;
        for(int i:nums)
            mp[i]++;
        int z=0;
        for(auto it:mp){
            if(it.second==0){
                z=it.first;
                break;
            }
        }
        return z;
    }
};
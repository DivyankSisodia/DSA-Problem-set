class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int l=0,e=n-1;
        while(l<e)
        {
            int sum=v[l].first + v[e].first;
            if(sum==target)
            {
                return {v[l].second,v[e].second};
            }
            else if(sum>target)
            {
                e--;
            }
            else if(sum<target)
            {
                l++;
            }
        } 
        return {-1,-1};
    }  
};
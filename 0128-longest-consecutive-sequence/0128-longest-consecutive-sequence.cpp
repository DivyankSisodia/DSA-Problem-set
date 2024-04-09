class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        
        set<int> s;
        for(int i=0; i<nums.size() ;i++){
            s.insert(nums[i]);
        }
        
        vector<int> v(s.begin(), s.end());
        
        int count = 1;
        int ans = 1;
        
        for(int i=1; i<v.size(); i++){
            if(v[i]-v[i-1] == 1){
                count++;
                ans = max(ans,count);
            }
            else{
                count = 1;
            }
        }
        return ans;
    }
};
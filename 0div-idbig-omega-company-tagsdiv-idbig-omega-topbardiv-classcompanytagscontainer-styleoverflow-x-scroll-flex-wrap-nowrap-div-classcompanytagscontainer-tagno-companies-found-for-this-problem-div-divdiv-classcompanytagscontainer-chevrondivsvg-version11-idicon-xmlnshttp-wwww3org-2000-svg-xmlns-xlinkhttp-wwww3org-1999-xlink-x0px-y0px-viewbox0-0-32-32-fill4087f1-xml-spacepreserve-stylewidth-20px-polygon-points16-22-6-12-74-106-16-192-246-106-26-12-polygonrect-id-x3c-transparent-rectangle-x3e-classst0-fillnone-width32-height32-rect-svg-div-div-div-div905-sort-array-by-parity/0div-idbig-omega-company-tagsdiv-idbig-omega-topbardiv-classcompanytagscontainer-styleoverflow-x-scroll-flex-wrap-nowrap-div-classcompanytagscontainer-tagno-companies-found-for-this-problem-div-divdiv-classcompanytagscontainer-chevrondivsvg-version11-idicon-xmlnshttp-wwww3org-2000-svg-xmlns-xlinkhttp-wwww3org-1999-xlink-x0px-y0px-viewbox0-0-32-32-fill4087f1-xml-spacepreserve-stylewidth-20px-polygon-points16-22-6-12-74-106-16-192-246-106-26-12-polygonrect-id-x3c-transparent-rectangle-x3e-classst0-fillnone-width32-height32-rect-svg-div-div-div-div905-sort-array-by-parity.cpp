class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        list<int> l;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                l.push_front(nums[i]);
            }
            else{
                l.push_back(nums[i]);
            }
        }
        
        for(auto it: l){
            ans.push_back(it);
        }
        return ans;
    }
};
class Solution {
public:
    
//     void solve(vector<int> nums, int curr,vector<vector<int>> &ans){
//         if(curr >= nums.size()){
//             ans.push_back(nums);
//             return;
//         }
        
//         for(int i=curr; i<nums.size(); i++){
//             swap(nums[curr], nums[i]);
//             solve(nums,i+1,ans);
//             swap(nums[curr], nums[i]);
//         }
        
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int i=0;
//         solve(nums,i,ans);
//         return ans;
//     }
    void solve(vector<int> nums,int index,vector<vector<int>> &ans){
        
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=index; j<nums.size(); j++){
            swap(nums[index],nums[j]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[j]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,index,ans);
        return ans;
    }
};
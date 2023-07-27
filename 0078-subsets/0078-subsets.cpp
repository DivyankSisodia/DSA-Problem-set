class Solution {
public:
    
    void solve(int i, int n, vector<int>nums, vector<int>path, vector<vector<int>>&ans){
        if(i >= n){
            ans.push_back(path);
            return;
        }
        
        solve(i+1,n,nums,path,ans);
        
        int x = nums[i];
        path.push_back(x);
        
        solve(i+1,n,nums,path,ans);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        solve(0,n,nums,path,ans);
        return ans;
    }
};
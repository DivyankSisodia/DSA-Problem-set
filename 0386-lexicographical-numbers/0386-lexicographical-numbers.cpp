class Solution {
public:
    void solve(int nums,int n, vector<int>&ans){
        if(nums > n){
            return;
        }
        
        ans.push_back(nums);
        solve(nums*10,n,ans);
        if(nums%10 != 9){
            solve(nums+1,n,ans);
        }
        
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        solve(1,n,ans);
        return ans;
    }
};
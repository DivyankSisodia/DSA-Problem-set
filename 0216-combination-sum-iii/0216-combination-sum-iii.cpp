class Solution {
public:
    
    void solve(int i, int k, int n, vector<int> &path, vector<vector<int>>& ans){
        if(n < 0 && path.size() > k){
            return;
        }
        if(n == 0 && path.size() == k){
            ans.push_back(path);
            return;
        }
        
        for(int ind = i; ind <= 9; ind++){
            path.push_back(ind);
            solve(ind+1, k, n-ind, path, ans);
            path.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(1, k, n, path, ans);
        return ans;
    }
};
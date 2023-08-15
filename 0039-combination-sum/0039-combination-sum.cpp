class Solution {
public:
    
    void solve(int n, int i, vector<int>& can, int target, vector<int>& path, vector<vector<int>>&      ans) {
        if (i == n) {
            if (target == 0) {
                ans.push_back(path);
            }
            return; 
        }

        if (target >= can[i]) {
            path.push_back(can[i]);
            solve(n, i, can, target - can[i], path, ans);
            path.pop_back();
        }

        solve(n, i + 1, can, target, path, ans);  // Corrected the index here
    }

    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = can.size();

        solve(n, 0, can, target, path, ans);
        return ans;
    }

};
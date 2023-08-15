class Solution {
public:
    
    void solve(int ind, vector<int>& can, int target, vector<int>& path, vector<vector<int>>&ans)       {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < can.size(); i++) {
            if (can[i] > target) {
                break;
            }

            if (i > ind && can[i] == can[i - 1]) {
                continue;
            }

            path.push_back(can[i]);
            solve(i + 1, can, target - can[i], path, ans);  // Use i + 1 here
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(can.begin(), can.end());
        solve(0, can, target, path, ans);

        return ans;
    }

};
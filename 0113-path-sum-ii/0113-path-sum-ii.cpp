/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int>res;
    
    void solve(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return;
        }
        sum = sum + root->val;
        res.push_back(root->val);
        
        if(!root->left && !root->right && sum == targetSum){
            ans.push_back(res);
        }
        
        solve(root->left,targetSum, sum);
        solve(root->right,targetSum, sum);
        
        res.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum ,0);
        return ans;
    }
};
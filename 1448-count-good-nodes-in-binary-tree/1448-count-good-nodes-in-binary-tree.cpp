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
    int ans = 0;
    void solve(TreeNode* root, int curr){
        if(root == NULL){
            return;
        }
        
        if(root->val >= curr){
            curr = root->val;
            ans++;
        }
        
        solve(root->left,curr);
        solve(root->right,curr);
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        solve(root,root->val);
        return ans;
    }
};

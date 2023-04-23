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
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int lvl = 0;
        int ans = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            lvl++;
            int sum = 0;
            int size = q.size();
            while(size--){
                TreeNode* top = q.front();
                q.pop();
                sum = sum + top->val;
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            if(sum > maxi){
                maxi = sum;
                ans = lvl;
            }
        }
        return ans;
    }
};
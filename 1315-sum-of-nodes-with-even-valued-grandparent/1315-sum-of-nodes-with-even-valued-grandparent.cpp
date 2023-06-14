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
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        if(root == NULL){
            return ans;
        }
        
        if(root->val % 2 == 0){
            if(root->left != NULL && root->left->left != NULL){
                ans = ans + root->left->left->val;
            }
            if(root->left != NULL && root->left->right != NULL){
                ans = ans + root->left->right->val;
            }
            if(root->right != NULL && root->right->left != NULL){
                ans = ans + root->right->left->val;
            }
            if(root->right != NULL && root->right->right != NULL){
                ans = ans + root->right->right->val;
            }
        }
        
        ans += sumEvenGrandparent(root->left);
        ans += sumEvenGrandparent(root->right);
        
        return ans;
    }
};
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
    // pehla bool true ya false return krne ke liye
    // aur int use kia height of tree use krne ke liye
    pair<bool,int> check(TreeNode* root){
        if(root == NULL){
            pair<bool,int> p{true,0};
            return p;
        }
        pair<bool,int> left = check(root->left);
        pair<bool,int> right = check(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool differnce = false;
        
        
        if(abs((left.second)-(right.second)) <=1 ){
            differnce = true;
        }
        pair<bool,int> ans;
        if(differnce && rightAns && leftAns){
            ans.first = true;
        }
        ans.second = max(left.second,right.second)+1;
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root).first;
    }
};
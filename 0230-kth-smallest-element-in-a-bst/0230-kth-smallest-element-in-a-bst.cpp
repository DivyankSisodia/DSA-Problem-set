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
//     int ans = -1;
    
//     int solve(TreeNode* root, int &i, int k){
//         if(root == NULL){
//             return -1;
//         }
//         if(root->left != NULL){
//             solve(root->left,i,k);
//         }
        
//         i++;
//         if(i == k){
//             ans = root->val;
//             // break;
//         }
//         if(root->right != NULL){
//             solve(root->right,i,k);
//         }
        
//         return ans;
        
//     }
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
        return -1;
    }
};
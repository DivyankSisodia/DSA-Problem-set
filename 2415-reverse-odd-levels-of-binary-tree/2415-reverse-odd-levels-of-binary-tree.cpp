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
// public:
    
    void dfs(TreeNode *p, TreeNode *q, int lvl)
    {
        if(!p && !q)
            return;
        if(lvl % 2 && p && q)
            swap(p->val, q->val);
        
        // swap the value of left's left children with value of right's right children
        dfs(p->left, q->right, lvl+1);

        // swap the value of left's right children with value of right's left children
        dfs(p->right, q->left, lvl+1);
    }

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        // do traversal only if left and right children exists for the given root
        if(root->left && root->right)
            dfs(root->left, root->right, 1);
        return root;
    }
};
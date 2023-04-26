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
    
int position(vector<int> &in, int n, int x){
    for(int i=0; i<n; i++){
        if(in[i] == x){
            return i;
        }
    }
    return -1;
}
    
TreeNode* solve(vector<int>& pre, vector<int>& in, int &preIndex, int inOrderStart, int inOrderEnd, int n){
    if(preIndex >= n || inOrderStart >inOrderEnd){
        return NULL;
    }
    int x = pre[preIndex++];
    TreeNode* element = new TreeNode(x);
    int posi = position(in,n,x);
    
    element->left = solve(pre,in,preIndex,inOrderStart,posi-1,n);
    element->right = solve(pre,in,preIndex,posi+1,inOrderEnd,n);
    
    return element;
    
}
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();
        int preIndex = 0;
        TreeNode* ans = solve(pre,in,preIndex,0,n-1,n);
        return ans;
    }
};
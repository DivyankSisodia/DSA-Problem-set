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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> s;
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> temp;
            
            
            for(int i=0; i<size; i++){
                TreeNode* res = q.front();
                q.pop();
                temp.push_back(res->val);
                
                if(res->left != NULL){
                    q.push(res->left);
                }
                if(res->right != NULL){
                    q.push(res->right);
                }
            }
            s.push(temp);
        }
        
        while(s.empty()==NULL){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};
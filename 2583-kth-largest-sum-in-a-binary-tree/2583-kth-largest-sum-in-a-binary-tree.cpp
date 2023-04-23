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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long maxi = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        // vector<int> ans;
        priority_queue<long long> pq;
        if(root == NULL){
            return -1;
        }
        
        while(!q.empty()){
            long long sum  =0;
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
            // ans.push_back(sum);
            pq.push(sum);
        }
        if(pq.size()<k)return -1;
        k=k-1;
        while(k--)pq.pop();
        return pq.top();
    }
};
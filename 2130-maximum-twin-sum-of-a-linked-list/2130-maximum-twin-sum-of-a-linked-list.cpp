/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        int i=0;
        int j=ans.size()-1;
        int maxi = INT_MIN;
        
        while(i<j){
            maxi = max(maxi, ans[i]+ans[j]);
            i++;
            j--;
        }
        return maxi;
    }
};
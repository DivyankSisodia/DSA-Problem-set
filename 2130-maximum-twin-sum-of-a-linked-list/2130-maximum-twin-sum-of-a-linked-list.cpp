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
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* next, *prev = NULL;
        while(slow!=NULL){
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        
        int maxi = 0;
        ListNode* entry = head;
        
        while(prev!=NULL){
            int x = entry->val + prev->val;
            maxi = max(maxi, x);
            prev = prev->next;
            entry = entry->next;
        }
        return maxi;
    }
};
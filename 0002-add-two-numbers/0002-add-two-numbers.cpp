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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* temp  = dummy;
        
        while(l1 || l2 || carry != 0){
            int sum = 0;
            if(l1 != NULL){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            
            int val = sum+carry;
            carry = val/10;
            ListNode* ans = new ListNode(val%10);
            
            temp->next = ans;
            temp = temp->next;
        }
        return dummy->next;
    }
};
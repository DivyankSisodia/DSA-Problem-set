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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        
        ListNode* leftEnd = left;
        ListNode* rightEnd = right;
        
        while(head!=NULL){
            if(head->val < x){
                leftEnd->next = head;
                leftEnd = leftEnd->next;
            }
            else{
                rightEnd->next = head;
                rightEnd = rightEnd->next;
            }
            head = head->next;
        }
        leftEnd->next = right->next;
        rightEnd->next = NULL;
        
        return left->next;
    }
    
};
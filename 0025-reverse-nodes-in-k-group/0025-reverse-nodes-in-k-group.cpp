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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //baki joh reverse nhi honge remainin parts
        ListNode* temp = head;
        int i=0;
        while(i<k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            i++;
        }
        
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        
        int cnt = 0;
        
        while(curr != NULL && cnt < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }
        return prev;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        ListNode* newH = head;
        ListNode* tail = head;
        int len = 1;
        
        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }
        
        tail->next = head;
        
        if(k = k%len){
            for(auto i=0; i<len-k; i++){
                tail = tail->next;
            }
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};
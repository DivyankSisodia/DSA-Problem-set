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
    
     ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode* answer = NULL; // define answer to null
        
        if(first == NULL) // if first is null, then what to merge...nothing
        {
            return second; // return second
        }
        
        if(second == NULL) // if second is null, then what to merge...nothing
        {
            return first; // return first
        }
        
        // if value of first is less than value of second,then give answer to first
        if(first -> val <= second -> val) 
        {
            answer = first;
            answer -> next = merge(first -> next, second); // and again call merge for answer's next
        }
        else // else give answer to second
        {
            answer = second;
            answer -> next = merge(first, second -> next); // and again call merge for answer's next
        }
        
        return answer; // finally return answer
    }
    
    ListNode* sortList(ListNode* head) {
     if(head == NULL || head ->next == NULL)
        return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp;
        
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = NULL;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1,l2);
    }
};
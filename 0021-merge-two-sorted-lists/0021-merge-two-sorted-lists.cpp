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
    
    ListNode* solve(ListNode* &p, ListNode* &q){
        ListNode* curr1 = p;
        ListNode* curr2 = q;
        ListNode* next1 = curr1->next;
        
        if(next1 == NULL){
            curr1->next = curr2;
            return p;
        }
        
        while((next1!=NULL) && (curr2!=NULL)){
            if((curr1->val <=curr2->val) && (curr2->val <=next1->val)){
                // 2nd list pr bhi ek next dal dete h aur list ko lost nhi hone dega
                ListNode* temp = curr2->next;
                curr2->next = next1;
                curr1->next = curr2;
                curr1 = curr1->next;
                curr2 = temp;
            }
            else{
                curr1 = curr1->next;
                next1 = next1->next;
                
                if(next1 == NULL){
                    curr1->next = curr2;
                    return p;
                }
            }
        }
        return p;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        if(list1->val <= list2->val){
            return solve(list1,list2);
        }
        else
            return solve(list2,list1);
    }
};
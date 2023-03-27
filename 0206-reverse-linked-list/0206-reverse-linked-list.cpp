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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL; //make new dumy node and assign it to NULL
        while(head != NULL){ 
            ListNode* next = head->next;  //head ke next ko 'next' assign kar diya     
            
            head->next = newHead;  //break the chain between head ka next 
            
            newHead = head;
            head = next;           
        }
       return newHead; 
        
    }
};
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

  ListNode* reverseList(ListNode* head){
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while(head!=NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

bool isPalindrome(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return true;
    }
    
    // Find the middle node of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the linked list
    ListNode* secondHalf = reverseList(slow);
    
    // Compare the first half with the reversed second half
    ListNode* curr1 = head;
    ListNode* curr2 = secondHalf;
    while(curr2 != NULL){
        if(curr1->val != curr2->val){
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    // Restore the original linked list
    reverseList(secondHalf);
    
    return true;
}

       
};
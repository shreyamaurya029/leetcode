/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //first exmaple hai 4, 5 ko link kar raha hai, to 5 ki value ki jagah 1 ki value daal do
        
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};
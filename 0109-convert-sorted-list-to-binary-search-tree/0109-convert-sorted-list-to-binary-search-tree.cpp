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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* getMidNode(ListNode* start, ListNode* nextToEnd)
    {
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast != nextToEnd && fast->next != nextToEnd)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* getRoot(ListNode* startNode, ListNode* nextToEndNode)
    {
        if (startNode == nextToEndNode) return NULL;  //Most important 
        
        ListNode* midNode =  getMidNode(startNode, nextToEndNode);
        TreeNode* currRoot = new TreeNode(midNode->val);
        
        currRoot->left = getRoot(startNode, midNode);
        currRoot->right = getRoot(midNode->next, nextToEndNode);
        
        return currRoot;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        TreeNode* root = getRoot(head, NULL);
        return root;
        
    }
};
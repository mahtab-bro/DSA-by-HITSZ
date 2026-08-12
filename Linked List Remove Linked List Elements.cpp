 Full Question
203. Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes that have Node.val == val and return the new head.
----------------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);  // Dummy before head to handle head removal
        dummy->next = head;  // Connect dummy to actual head
        ListNode* prev = dummy;  // Prev tracks node before current
        ListNode* curr = head;  // Current tracks node we're checking
        
        while (curr != nullptr) {  // Walk through entire list
            if (curr->val == val) {  // Found node to remove
                prev->next = curr->next;  // Skip current node
            } else {  // Not a match
                prev = curr;  // Move prev forward
            }
            curr = curr->next;  // Always move curr forward
        }
        
        ListNode* result = dummy->next;  // Save new head
        delete dummy;  // Clean up dummy
        return result;  // Return new head
    }
};

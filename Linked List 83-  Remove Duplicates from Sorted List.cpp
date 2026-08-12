 Full Question
83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
  -------------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;                 // Empty list, nothing to remove
        ListNode* curr = head;                               // Start walking from head
        while (curr != nullptr && curr->next != nullptr) {   // While current and next exist
            if (curr->val == curr->next->val) {              // Found duplicate adjacent
                curr->next = curr->next->next;               // Skip the duplicate node
            } else {                                         // No duplicate found
                curr = curr->next;                           // Move to next node
            }
        }
        return head;                                         // Return original head (it never changes)
    }
};

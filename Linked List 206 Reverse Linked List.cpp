Full Question
206. Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

  -------------------------------------------------------------------------------------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  // Points to the reversed list's head
        ListNode* curr = head;  // Walks through original list
        
        while (curr != nullptr) {  // While there are nodes to process
            ListNode* next = curr->next;  // SAVE the rest of the list
            curr->next = prev;  // Reverse: point backward to prev
            prev = curr;  // Move prev forward (prev becomes current node)
            curr = next;  // Move curr forward using saved pointer
        }
        
        return prev;  // Prev is the new head of reversed list
    }
};

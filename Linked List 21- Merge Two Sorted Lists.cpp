 Full Question
21. Merge Two Sorted Lists

You are given the head of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
  --------------------------------------------------------------------------------------
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node avoids special case for empty list
        ListNode* dummy = new ListNode(0);
        // Tail always points to last node of merged list
        ListNode* tail = dummy;

        // Loop while both lists have nodes to compare
        while (list1 != nullptr && list2 != nullptr) {
            // If list1's value is smaller or equal, take from list1
            if (list1->val <= list2->val) {
                // Attach list1 node to merged list
                tail->next = list1;
                // Move list1 forward
                list1 = list1->next;
            } else {
                // Otherwise take from list2
                tail->next = list2;
                // Move list2 forward
                list2 = list2->next;
            }
            // Move tail to the newly attached node
            tail = tail->next;
        }

        // Attach remaining nodes from whichever list is not empty
        if (list1 != nullptr) {
            tail->next = list1;  // Attach rest of list1
        } else {
            tail->next = list2;  // Attach rest of list2
        }

        // Save the real head before deleting dummy
        ListNode* result = dummy->next;
        // Clean up dummy node (good practice)
        delete dummy;
        // Return the merged list head
        return result;
    }
};

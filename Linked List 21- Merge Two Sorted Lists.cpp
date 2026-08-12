 Full Question
21. Merge Two Sorted Lists

You are given the head of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
  --------------------------------------------------------------------------------------
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // WHY: A dummy node simplifies edge cases.
        //      We don't need to worry if the merged list is empty.
        //      'tail' will always point to the last node of the merged list.
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // WHY: Loop runs while BOTH lists have nodes left to compare.
        //      If either becomes empty, we stop comparing and just attach the rest.
        while (list1 != nullptr && list2 != nullptr) {

            // WHY: Pick the smaller value to maintain sorted order.
            //      If equal, either works. We pick list1 for consistency.
            if (list1->val <= list2->val) {
                // WHY: Attach list1's current node to the merged list.
                tail->next = list1;
                // WHY: Move list1 forward to its next node.
                list1 = list1->next;
            } else {
                // WHY: list2 has the smaller (or equal) value.
                tail->next = list2;
                list2 = list2->next;
            }

            // WHY: Move tail forward to the node we just attached.
            //      Tail always stays at the end of the merged list.
            tail = tail->next;
        }

        // WHY: At this point, at least one list is empty.
        //      Attach the remaining list (if any) to tail.
        //      If both are empty, this sets tail->next = nullptr (already null).
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // WHY: dummy->next is the real head of the merged list.
        //      We delete dummy to avoid memory leak (good practice, but LeetCode ignores it).
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

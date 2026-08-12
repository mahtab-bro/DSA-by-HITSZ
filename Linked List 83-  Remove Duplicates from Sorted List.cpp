 Full Question
83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
  -------------------------------------------------------
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
    ListNode* deleteDuplicates(ListNode* head) {
        // WHY: If the list is empty, there's nothing to remove.
        //       Just return nullptr.
        if (head == nullptr) {
            return nullptr;
        }

        // WHY: 'curr' will walk through the list.
        //       We start from head and compare each node with the next one.
        ListNode* curr = head;

        // WHY: Loop runs as long as there is a current node AND a next node.
        //       If curr->next is null, we've reached the end - stop.
        while (curr != nullptr && curr->next != nullptr) {

            // WHY: Since the list is sorted, duplicates are always adjacent.
            //       If current value equals next value, we found a duplicate!
            if (curr->val == curr->next->val) {

                // WHY: Skip the duplicate node by making curr->next
                //       point to the node after the duplicate.
                //       The duplicate node is now "orphaned" (we don't delete
                //       it because LeetCode handles memory automatically).
                curr->next = curr->next->next;

                // WHY: We DO NOT move curr forward here!
                //       Because the new curr->next might ALSO be a duplicate.
                //       Example: 1 -> 1 -> 1 -> 2
                //       After removing the second 1, we need to check
                //       first 1 against the third 1 again.
                //       If we moved curr, we'd miss the third 1![reference:12]
            } else {
                // WHY: No duplicate found - values are different.
                //       Move curr forward to the next node and keep checking.
                curr = curr->next;
            }
        }

        // WHY: Return the head of the modified list.
        //       The head never changes in this problem (we only remove nodes
        //       after the head, never the head itself).
        return head;
    }
};

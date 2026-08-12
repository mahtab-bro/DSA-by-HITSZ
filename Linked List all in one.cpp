// ============================================================================
// COMPLETE LINKED LIST PROBLEMS SOLUTION FILE
// All 5 LeetCode-style problems with examples and solutions
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// NODE STRUCTURE (Common for all problems)
// ============================================================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;  // Only used for doubly linked list (Problem 5)
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next), prev(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* prev) : val(x), next(next), prev(prev) {}
};

// ============================================================================
// PROBLEM 1: LeetCode 83 - Remove Duplicates from Sorted List
// ============================================================================

/*
PROBLEM STATEMENT:
Given the head of a sorted linked list, delete all duplicates such that each 
element appears only once. Return the linked list sorted as well.

EXAMPLES:
Input: head = [1,1,2]     Output: [1,2]
Input: head = [1,1,2,3,3] Output: [1,2,3]
Input: head = []          Output: []

TIME: O(N) | SPACE: O(1)
*/

class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;  // Empty list, nothing to remove
        ListNode* curr = head;  // Start walking from head
        while (curr != nullptr && curr->next != nullptr) {  // While current and next exist
            if (curr->val == curr->next->val) {  // Found duplicate adjacent
                curr->next = curr->next->next;  // Skip the duplicate node
            } else {  // No duplicate found
                curr = curr->next;  // Move to next node
            }
        }
        return head;  // Return original head (it never changes)
    }
};

// ============================================================================
// PROBLEM 2: LeetCode 21 - Merge Two Sorted Lists
// ============================================================================

/*
PROBLEM STATEMENT:
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists.
Return the head of the merged linked list.

EXAMPLES:
Input: list1 = [1,2,4], list2 = [1,3,4]     Output: [1,1,2,3,4,4]
Input: list1 = [], list2 = []               Output: []
Input: list1 = [], list2 = [0]              Output: [0]

TIME: O(N + M) | SPACE: O(1)
*/

class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);  // Dummy node simplifies edge cases
        ListNode* tail = dummy;  // Tail points to last node of merged list
        while (list1 != nullptr && list2 != nullptr) {  // While both lists have nodes
            if (list1->val <= list2->val) {  // Take from list1 if smaller or equal
                tail->next = list1;  // Attach list1 node
                list1 = list1->next;  // Move list1 forward
            } else {  // Take from list2
                tail->next = list2;  // Attach list2 node
                list2 = list2->next;  // Move list2 forward
            }
            tail = tail->next;  // Move tail to newly attached node
        }
        tail->next = (list1 != nullptr) ? list1 : list2;  // Attach remaining list
        ListNode* result = dummy->next;  // Save real head
        delete dummy;  // Clean up dummy
        return result;  // Return merged list head
    }
};

// ============================================================================
// PROBLEM 3: LeetCode 203 - Remove Linked List Elements
// ============================================================================

/*
PROBLEM STATEMENT:
Given the head of a linked list and an integer val, remove all the nodes that 
have Node.val == val, and return the new head.

EXAMPLES:
Input: head = [1,2,6,3,4,5,6], val = 6     Output: [1,2,3,4,5]
Input: head = [], val = 1                  Output: []
Input: head = [7,7,7,7], val = 7           Output: []

TIME: O(N) | SPACE: O(1)
*/

class Solution203 {
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

// ============================================================================
// PROBLEM 4: LeetCode 206 - Reverse Linked List
// ============================================================================

/*
PROBLEM STATEMENT:
Given the head of a singly linked list, reverse the list, and return the reversed list.

EXAMPLES:
Input: head = [1,2,3,4,5]     Output: [5,4,3,2,1]
Input: head = [1,2]           Output: [2,1]
Input: head = []              Output: []

TIME: O(N) | SPACE: O(1)
*/

class Solution206 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  // Points to the reversed list's head
        ListNode* curr = head;  // Walks through original list
        
        while (curr != nullptr) {  // While there are nodes to process
            ListNode* next = curr->next;  // SAVE the rest of the list (CRITICAL!)
            curr->next = prev;  // Reverse: point backward to prev
            prev = curr;  // Move prev forward (prev becomes current node)
            curr = next;  // Move curr forward using saved pointer
        }
        
        return prev;  // Prev is the new head of reversed list
    }
};

// ============================================================================
// PROBLEM 5: Exercise 5.5 - Reverse a Doubly Linked List
// ============================================================================

/*
PROBLEM STATEMENT:
Given the head of a doubly linked list, reverse the list and return the new head.
Each node has both 'next' and 'prev' pointers.

EXAMPLES:
Input: nullptr <- [1] <-> [2] <-> [3] <-> [4] -> nullptr
Output: nullptr <- [4] <-> [3] <-> [2] <-> [1] -> nullptr

Input: nullptr <- [1] -> nullptr
Output: nullptr <- [1] -> nullptr

TIME: O(N) | SPACE: O(1)
*/

class Solution5 {
public:
    ListNode* reverseDoublyList(ListNode* head) {
        // Empty list or single node - nothing to reverse
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* curr = head;  // Start from head
        ListNode* newHead = nullptr;  // Will store the new head
        
        while (curr != nullptr) {  // Process every node
            // Swap next and prev pointers
            ListNode* temp = curr->next;  // Save original next
            curr->next = curr->prev;  // Next becomes prev
            curr->prev = temp;  // Prev becomes original next
            
            newHead = curr;  // Update new head (ends at last node)
            curr = curr->prev;  // Move to next node (which is now in prev)
        }
        
        return newHead;  // New head is original tail
    }
};

// ============================================================================
// HELPER FUNCTIONS (For testing)
// ============================================================================

// Print a singly linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Print a doubly linked list (forward)
void printDoublyList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Create a linked list from array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Create a doubly linked list from array
ListNode* createDoublyList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr->next->prev = curr;
        curr = curr->next;
    }
    return head;
}

// Delete a linked list (free memory)
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================================================
// MAIN FUNCTION - Test all solutions
// ============================================================================

int main() {
    cout << "========================================" << endl;
    cout << "LINKED LIST PROBLEMS - COMPLETE SOLUTIONS" << endl;
    cout << "========================================\n" << endl;
    
    // ======================================================================
    // PROBLEM 1: Remove Duplicates from Sorted List
    // ======================================================================
    cout << "PROBLEM 1: Remove Duplicates from Sorted List (LeetCode 83)" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    int arr1[] = {1, 1, 2, 3, 3};
    ListNode* head1 = createList(arr1, 5);
    cout << "Input:  ";
    printList(head1);
    
    Solution83 s83;
    ListNode* result1 = s83.deleteDuplicates(head1);
    cout << "Output: ";
    printList(result1);
    cout << "Expected: 1 -> 2 -> 3\n" << endl;
    deleteList(result1);
    
    // ======================================================================
    // PROBLEM 2: Merge Two Sorted Lists
    // ======================================================================
    cout << "PROBLEM 2: Merge Two Sorted Lists (LeetCode 21)" << endl;
    cout << "------------------------------------------------" << endl;
    
    int arr2a[] = {1, 2, 4};
    int arr2b[] = {1, 3, 4};
    ListNode* list1 = createList(arr2a, 3);
    ListNode* list2 = createList(arr2b, 3);
    cout << "Input:  list1 = ";
    printList(list1);
    cout << "        list2 = ";
    printList(list2);
    
    Solution21 s21;
    ListNode* result2 = s21.mergeTwoLists(list1, list2);
    cout << "Output: ";
    printList(result2);
    cout << "Expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4\n" << endl;
    deleteList(result2);
    
    // ======================================================================
    // PROBLEM 3: Remove Linked List Elements
    // ======================================================================
    cout << "PROBLEM 3: Remove Linked List Elements (LeetCode 203)" << endl;
    cout << "------------------------------------------------------" << endl;
    
    int arr3[] = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head3 = createList(arr3, 7);
    cout << "Input:  head = ";
    printList(head3);
    cout << "        val = 6" << endl;
    
    Solution203 s203;
    ListNode* result3 = s203.removeElements(head3, 6);
    cout << "Output: ";
    printList(result3);
    cout << "Expected: 1 -> 2 -> 3 -> 4 -> 5\n" << endl;
    deleteList(result3);
    
    // ======================================================================
    // PROBLEM 4: Reverse Linked List
    // ======================================================================
    cout << "PROBLEM 4: Reverse Linked List (LeetCode 206)" << endl;
    cout << "----------------------------------------------" << endl;
    
    int arr4[] = {1, 2, 3, 4, 5};
    ListNode* head4 = createList(arr4, 5);
    cout << "Input:  ";
    printList(head4);
    
    Solution206 s206;
    ListNode* result4 = s206.reverseList(head4);
    cout << "Output: ";
    printList(result4);
    cout << "Expected: 5 -> 4 -> 3 -> 2 -> 1\n" << endl;
    deleteList(result4);
    
    // ======================================================================
    // PROBLEM 5: Reverse Doubly Linked List
    // ======================================================================
    cout << "PROBLEM 5: Reverse Doubly Linked List (Exercise 5.5)" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    int arr5[] = {1, 2, 3, 4};
    ListNode* head5 = createDoublyList(arr5, 4);
    cout << "Input:  ";
    printDoublyList(head5);
    
    Solution5 s5;
    ListNode* result5 = s5.reverseDoublyList(head5);
    cout << "Output: ";
    printDoublyList(result5);
    cout << "Expected: 4 <-> 3 <-> 2 <-> 1\n" << endl;
    deleteList(result5);
    
    cout << "========================================" << endl;
    cout << "ALL PROBLEMS COMPLETED SUCCESSFULLY!" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

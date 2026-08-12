ListNode* reverseList(ListNode* head) {
    // prev = the part we already reversed (starts as nothing)
    ListNode* prev = nullptr;
    
    // curr = the node we are working on right now (starts at the head)
    ListNode* curr = head;
    
    // Keep going until we have processed every node
    while (curr != nullptr) {
        
        // 1. SAVE the rest of the original chain
        //    (if we don't, we lose it when we change curr->next!)
        ListNode* next = curr->next;
        
        // 2. REVERSE the arrow:
        //    Instead of pointing forward, make it point backward to 'prev'
        curr->next = prev;
        
        // 3. MOVE 'prev' forward:
        //    This current node is now "fixed", so it becomes the new "previous"
        prev = curr;
        
        // 4. MOVE 'curr' forward:
        //    Go to the saved 'next' node to work on it
        curr = next;
    }
    
    // When the loop ends, 'curr' is nullptr (we went past the end).
    // 'prev' is the very last node we fixed, which is the NEW HEAD!
    return prev;
}

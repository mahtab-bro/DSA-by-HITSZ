// Function to remove all nodes with value 6
ListNode* removeElements(ListNode* head, int val) {
    
    // ============================================================
    // STEP 1: Create a dummy node (fake node)
    // ============================================================
    // Why? So we don't have to handle the "removing the head" case separately!
    // The dummy node acts like a shield. It's like putting a fake plate
    // at the bottom of a stack so every plate is "in the middle".
    // ============================================================
    ListNode* dummy = new ListNode(0);  // Create fake node with value 0
    
    // ============================================================
    // STEP 2: Connect dummy to the real list
    // ============================================================
    // Now our list looks like: [0] -> [1] -> [2] -> [6] -> [3] -> [4] -> nullptr
    // The dummy node (0) is now the FIRST node, and the real head (1) is second.
    // This means: EVERY real node now has a node BEFORE it (including the old head)!
    // ============================================================
    dummy->next = head;
    
    // ============================================================
    // STEP 3: Create prev pointer starting at dummy
    // ============================================================
    // prev will always point to the node BEFORE the one we're checking.
    // This is important because to delete a node, we need the node BEFORE it.
    // ============================================================
    ListNode* prev = dummy;
    
    // ============================================================
    // STEP 4: Traverse the list and remove nodes with value 6
    // ============================================================
    // We use WHILE because we need to KEEP CHECKING each node
    // until we reach the end of the list.
    // 
    // Condition: prev->next != nullptr
    // - Check: "Is there a node AFTER prev?"
    // - If YES: Process that node
    // - If NO: We've reached the end, stop the loop!
    // ============================================================
    while (prev->next != nullptr) {
        
        // ============================================================
        // STEP 4a: Check if the NEXT node has the value we want to remove
        // ============================================================
        // Why prev->NEXT? Because we need to know the node AFTER prev.
        // We CANNOT delete prev itself because we need prev to reconnect the list.
        // ============================================================
        if (prev->next->val == val) {  // Is the NEXT node = 6?
            
            // ============================================================
            // STEP 4b: DELETE the node!
            // ============================================================
            // 1. Save the node we want to delete in a temporary pointer
            // 2. Make prev skip over the node to delete (reconnect the list)
            // 3. Delete the node from memory (PREVENT MEMORY LEAK!)
            // ============================================================
            ListNode* toDelete = prev->next;   // Save node to delete (6)
            prev->next = toDelete->next;       // Skip over it: [2] -> [3]
            delete toDelete;                   // Free memory of deleted node
            
            // IMPORTANT: prev DOES NOT move forward here!
            // Why? Because after deletion, prev->next now points to the NEXT node
            // (which is [3]), and we need to check that one too!
            
        } else {
            // ============================================================
            // STEP 4c: No deletion needed, just move prev forward
            // ============================================================
            // The NEXT node doesn't have value 6, so we just move prev
            // to the next node and continue checking.
            // ============================================================
            prev = prev->next;  // Move prev to the next node
        }
    }
    
    // ============================================================
    // STEP 5: Get the new head (remove dummy from the list)
    // ============================================================
    // dummy->next now points to the REAL first node (which might be
    // the original head OR a new head if the original head was deleted)
    // ============================================================
    head = dummy->next;
    
    // ============================================================
    // STEP 6: Delete the dummy node (clean up memory)
    // ============================================================
    // We created dummy with "new", so we must delete it to prevent
    // memory leaks. This deletes the fake node but LEAVES the real list intact.
    // ============================================================
    delete dummy;
    
    // ============================================================
    // STEP 7: Return the new head of the list
    // ============================================================
    return head;
}

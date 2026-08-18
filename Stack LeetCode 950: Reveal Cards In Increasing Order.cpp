Full Question
You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.

If there are still cards in the deck, put the next top card at the bottom of the deck.

If there are still unrevealed cards, go back to step 1. Otherwise, stop.

Return an ordering of the deck that would reveal the cards in increasing order.
  -------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();                    // Get total number of cards
        queue<int> q;                           // Queue to track positions in final deck
        
        // Initialize queue with all indices 0 to n-1
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        
        sort(deck.begin(), deck.end());         // Sort deck in increasing order
        
        vector<int> result(n);                  // Final deck arrangement
        
        // Place each sorted card at correct position
        for (int card : deck) {
            int idx = q.front();                // Get next available position
            q.pop();                            // Remove that position
            result[idx] = card;                 // Place card at that position
            
            // Move next front index to back (simulate forward process backward)
            if (!q.empty()) {
                int nextIdx = q.front();
                q.pop();
                q.push(nextIdx);
            }
        }
        
        return result;                          // Return the revealed deck order
    }
};

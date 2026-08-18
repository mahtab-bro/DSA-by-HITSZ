Full Question
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n-1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where tickets[i] is the number of tickets that the ith person would like to buy.

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.
------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;  // Queue to store person indices
        
        // Push all person indices into queue
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        
        int time = 0;  // Track total time elapsed
        
        while (!q.empty()) {
            int person = q.front();  // Current person at front
            q.pop();
            
            time++;  // Takes 1 second to buy 1 ticket
            tickets[person]--;  // They bought 1 ticket
            
            // If this is our target person and they're done
            if (person == k && tickets[person] == 0) {
                return time;
            }
            
            // If person still needs more tickets, go to back of line
            if (tickets[person] > 0) {
                q.push(person);
            }
        }
        
        return time;  // Fallback (should never reach here)
    }
};

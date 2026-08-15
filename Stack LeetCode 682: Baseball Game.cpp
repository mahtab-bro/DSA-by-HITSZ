You are keeping scores for a baseball game with strange rules. At the beginning, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation:

Integer x → Record a new score of x

"+" → Record a new score that is the sum of the previous two scores

"D" → Record a new score that is double the previous score

"C" → Invalidate the previous score, removing it from the record

Return the sum of all scores on the record after applying all operations.
---------------------------------------------------------------------------------------------
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;  // Stack to store all valid scores
        
        for (string op : operations) {
            if (op == "+") {
                // Get top two scores
                int a = st.top();   // Most recent score
                st.pop();
                int b = st.top();   // Second most recent score
                st.push(a);         // Restore a
                st.push(a + b);     // Add sum of previous two
            } 
            else if (op == "D") {
                // Double the most recent score
                st.push(2 * st.top());
            } 
            else if (op == "C") {
                // Remove the most recent score (undo)
                st.pop();
            } 
            else {
                // It's a number, convert to int and push
                st.push(stoi(op));
            }
        }
        
        // Calculate sum of all scores in stack
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};

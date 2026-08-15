Full Question
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
  ---------------------------------------------------------------------------------------------
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;  // Stack to store characters not yet removed
        
        for (char c : s) {
            // If stack has characters and top matches current
            if (!st.empty() && st.top() == c) {
                st.pop();  // Remove the matching character
            } else {
                st.push(c);  // No match, keep this character
            }
        }
        
        // Build result string from stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;  // Reverse order since stack is LIFO
            st.pop();
        }
        
        return result;
    }
};

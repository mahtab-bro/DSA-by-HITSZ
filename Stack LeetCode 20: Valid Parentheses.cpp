Full Question
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
---------------------------------------------------------------------------------
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Stack to store opening brackets
        
        for (char c : s) {
            // If opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If closing bracket, check matching
            else {
                if (st.empty()) return false;  // No opening bracket to match
                
                char top = st.top();
                // Check if top matches the current closing bracket
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;  // Mismatched brackets
                }
                st.pop();  // Match found, remove the opening bracket
            }
        }
        
        return st.empty();  // All brackets must be closed
    }
};

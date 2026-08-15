Full Question
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

Return the resulting string.
------------------------------------------------------------------------------------
class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> st;  // Stack to reverse the prefix
        int i = 0;
        
        // Push characters until we find ch
        for (i = 0; i < word.length(); i++) {
            st.push(word[i]);
            if (word[i] == ch) {
                break;  // Found first occurrence, stop pushing
            }
        }
        
        // If ch wasn't found, return original word
        if (i == word.length()) {
            return word;
        }
        
        // Build result: pop from stack (reversed prefix) + remaining suffix
        string result = "";
        while (!st.empty()) {
            result += st.top();  // Pop in reverse order
            st.pop();
        }
        
        // Append remaining characters after ch
        for (int j = i + 1; j < word.length(); j++) {
            result += word[j];
        }
        
        return result;
    }
};

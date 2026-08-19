void search(string& pat, string& txt) {
    int M = pat.size(); // M = length of the pattern (e.g., 4)
    int N = txt.size(); // N = length of the text (e.g., 10)

    // Story: "i" is the starting position of our magnifying glass.
    // We can only slide until the glass fits inside the text.
    // That means: i can go from 0 up to (N - M).
    for (int i = 0; i <= N - M; i++) {
        
        int j; // "j" is the counter for checking letters inside the glass.

        // Story: Look inside the glass. Start at j=0 (first letter of pattern).
        // Check if Text[i + j] matches Pattern[j].
        // If they match, increase j and check the next letter.
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break; // OH NO! A letter didn't match. Break out of this inner loop.
            }
        }

        // Story: If we finished the inner loop and "j" reached "M" (the full length),
        // that means we NEVER hit a mismatch. WE FOUND IT!
        if (j == M) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

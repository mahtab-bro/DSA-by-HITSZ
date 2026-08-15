// 🎯 Goal: {a,b,c} → {a,b,c,c,b,a}
stack<string> s;
int q_size = q.size();
for (int i = 0; i < q_size; i++) {
    string str = q.front();
    q.pop();
    s.push(str);
    q.push(str);        // Keep original order first
}
while (!s.empty()) {
    q.push(s.top());    // Add reversed at the end
    s.pop();
}
// Result: original + reversed = MIRRORED!
------------------------------------------------------------
// When to use STACK:
if (need to process in reverse order) use stack
if (need to match pairs/parentheses) use stack
if (need to undo/backtrack) use stack

// When to use QUEUE:
if (need to preserve original order) use queue
if (need to process in arrival order) use queue
if (need to simulate line/queue) use queue

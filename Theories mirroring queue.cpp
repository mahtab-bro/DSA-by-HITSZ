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

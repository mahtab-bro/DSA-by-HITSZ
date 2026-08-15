// 🎯 Goal: Reverse order of elements in queue
stack<int> s;
while (!q.empty()) {
    s.push(q.front());  // Queue front → Stack top
    q.pop();
}
while (!s.empty()) {
    q.push(s.top());    // Stack top → Queue back
    s.pop();
}
// Now q is reversed!

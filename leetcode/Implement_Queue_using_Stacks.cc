class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
        auto temp(s);
        while (!r.empty())
            r.pop();
        while (!temp.empty()) {
            r.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        r.pop();
        auto temp(r);
        while (!s.empty())
            s.pop();
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return r.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
    
private:
    stack<int> s;
    stack<int> r;
};

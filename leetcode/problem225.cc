class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> temp;
        while (q.size() > 1) {
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

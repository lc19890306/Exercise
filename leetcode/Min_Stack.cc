class MinStack {
public:
    void push(int x) {
        vec.push_back(x);
        if (min.empty() || x <= min.back())
            min.push_back(x);
    }

    void pop() {
        if (vec.empty())
	    return;
        if (vec.back() == min.back())
            min.pop_back();
        vec.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return min.back();
    }
    
private:
    vector<int> vec;
    vector<int> min;
};

// Heap solution - O(n) space complexity
class MedianFinder {
public:

    // Adds a number into the data structure.
  // O(logn) time complexity
    void addNum(int num) {
        if (left.empty() && right.empty()) {
            median = num;
            left.push(num);
            return;
        }
        if (num < median) {
            if (left.size() > right.size()) {
                right.push(left.top());
                left.pop();
            }
            left.push(num);
        }
        else {
            if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }
            right.push(num);
        }
        if (left.size() > right.size())
            median = left.top();
        else if (right.size() > left.size())
            median = right.top();
        else
            median = (left.top() + right.top()) / 2.0;
    }

    // Returns the median of current data stream
  // O(1) time complexity
    double findMedian() {
        return median;
    }
    
private:
  // a max heap
    priority_queue<int> left;
  // a min heap
    priority_queue<int, vector<int>, greater<int> > right;
    double median;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

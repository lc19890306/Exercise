// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    peeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	  // cache returned element from Iterator::next() because we are only allowed to use Iterator::next() to peek the next element
	    if (!peeked && Iterator::hasNext()) {
	        peeked_element = Iterator::next();
	        peeked = true;
	        return peeked_element;
	    }
        return peeked_element;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	  // if the next element is cached, directly return it but not call Iterator::next(), which is wrong
	    if (peeked) {
	        peeked = false;
	        return peeked_element;
	    }
	    else if (Iterator::hasNext())
	        return Iterator::next();
	}

	bool hasNext() const {
	  // use peeked flag to adjust hasNext because for the call sequence <next, peek, hasNext>, after call peek althought the iterator actually points to the last element, hasNext should not return false
	  // because peek returns the last element and we assume the iterator still points to the last but one element
	    if (peeked)
	        return true;
	    return Iterator::hasNext();
	}
	
private:
    bool peeked;
    int peeked_element;
};

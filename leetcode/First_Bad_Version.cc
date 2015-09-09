// Iterative version1
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1)
            return 0;
        return bin_search(1, (long)n + 1);
    }
    
private:
    int bin_search(long first, long last) {
        if (first == last)
            return last;
        auto mid((first + last) >> 1);
        if (isBadVersion(mid))
            return bin_search(first, mid);
        return bin_search(mid + 1, last);
    }
};

// Iterative version2 - better than iterative version1
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1)
            return 0;
        return bin_search(1, n);
    }
    
private:
    int bin_search(int first, int last) {
        if (first == last)
            return last;
        while (first < last) {
	  // !!!!!!!!!!!!!!! BE CAREFUL!!! Overflow in here!!!
            auto mid(first + ((last - first) >> 1));
            if (isBadVersion(mid))
                last = mid;
            else
                first = mid + 1;
        }
        return last;
    }
};

// Iterative vesion3 - the best version for this problem
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1)
            return 0;
        int first(1), last(n);
        while (first < last) {
            auto mid(first + ((last - first) >> 1));
            if (isBadVersion(mid))
                last = mid;
            else
                first = mid + 1;
        }
        return last;
    }
};

// Recursive version - based on iterative version2
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1)
            return 0;
        return bin_search(1, n);
    }
    
private:
    int bin_search(int first, int last) {
        if (first == last)
            return last;
        auto mid(first + ((last - first) >> 1));
        if (isBadVersion(mid))
            return bin_search(first, mid);
        return bin_search(mid + 1, last);
    }
};

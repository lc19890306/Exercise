// O(n) time complexity
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n(citations.size());
        int j(0);
        for (int i(n - 1); i >= 0; --i, ++j)
            if (j + 1 > citations[i])
                return j;
        return j;
    }
};

// Binary search solution - O(logn) time complexity
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int l(0), r(citations.size() - 1);
        while (l < r) {
            auto mid((l + r) >> 1);
            if (citations.size() - mid == citations[mid])
                return citations.size() - mid;
            if (citations.size() - mid > citations[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (citations.size() - l <= citations[l])
            return citations.size() - l;
        else
            return citations.size() - l - 1;
    }
};

// Optimized binary search solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int l(0), r(citations.size() - 1);
        while (l <= r) {
            auto mid((l + r) >> 1);
            if (citations.size() - mid == citations[mid])
                return citations.size() - mid;
            if (citations.size() - mid > citations[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return citations.size() - r - 1;
    }
};

// Further optimized binary search solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int first(0), count(citations.size()), size(citations.size());
        while (count > 0) {
            auto step(count >> 1);
            auto mid(first + step);
            if (citations[mid] < size - mid) {
                first = mid + 1;
                count -= (step + 1);
            }
            else
                count = step;
        }
        return size - first;
    }
};

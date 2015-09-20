// class Solution {
// public:
//     /**
//      * @param nums: A list of integers.
//      * @return: An integer denotes the middle number of the array.
//      */
//     int median(vector<int> &nums) {
//         // write your code here
//         auto n((nums.size() - 1) >> 1);
//         nth_element(nums.begin(), nums.begin() + n, nums.end());
//         return nums[n];
//     }
// };

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        auto n((nums.size() - 1) >> 1);
        median(nums.begin(), nums.begin() + n, nums.end());
        return nums[n];
    }
    
private:
    typedef vector<int>::iterator Iterator;
    
    Iterator partition(Iterator first, Iterator last, int pivot) {
        while (true) {
            while (first != last && *first <= pivot) ++first;
            if (first == last--) break;
            while (first != last && pivot < *last) --last;
            if (first == last) break;
            swap(*first++, *last);
        }
        return first;
    }
    
    int median(const int &a, const int &b, const int &c) {
        if (a <= b && b <= c) return b;
        if (a <= c && c <= b) return c;
        if (b <= a && a <= c) return a;
        if (b <= c && c <= a) return c;
        if (c <= a && a <= b) return a;
        if (c <= b && b <= a) return b;
    }
    
    void median(Iterator first, Iterator mid, Iterator last) {
        while (distance(first, last) > 3) {
            auto it(partition(first, last, median(*first, first[distance(first, last) >> 1], last[-1])));
            if (it <= mid)
                first = it;
            else
                last = it;
        }
        sort(first, last);
    }
};

int main() {
  vector<int> nums{-1, -2, -3, -100, -1, -50};
  Solution s;
  auto ret(s.median(nums));
  return 0;
}

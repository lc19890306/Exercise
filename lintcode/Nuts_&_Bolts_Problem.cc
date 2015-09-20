// Correct solution but TLE
// lintcode system is shit!
// the entire process is like quicksort
// first select a bolt as pivot, sort nuts
// then select a nut the index of which is the same as the previous pivot as new pivot, sort bolts
// recursively
/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        qsort(nuts, bolts, 0, nuts.size(), compare);
    }
    
private:
    void qsort(vector<string> &nuts, vector<string> &bolts, int first, int last, Comparator compare) {
        if (last - first < 2)
            return;
        // Randomly choose a bolt as a pivot for nuts partition.
        default_random_engine gen((random_device())());
        uniform_int_distribution<int> dis(first, last - 1);
        auto idx(partition(nuts, first, last, bolts[dis(gen)], compare));
        partition(bolts, first, last, nuts[idx], compare);
        qsort(nuts, bolts, first, idx, compare);
        qsort(nuts, bolts, idx, last, compare);
    }
    
    int partition(vector<string> &vec, int first, int last, const string &pivot, Comparator compare) {
        --last;
        while (first < last) {
            while (first < last && 
                (-1 == compare.cmp(vec[first], pivot) ||
                2 == compare.cmp(vec[first], pivot) &&
                1 == compare.cmp(pivot, vec[first]))) ++first;
            while (first < last &&
                (1 == compare.cmp(vec[last], pivot) ||
                2 == compare.cmp(vec[last], pivot) &&
                -1 == compare.cmp(pivot, vec[last]))) --last;
            if (first < last)
                swap(vec[first], vec[last]);
        }
        return last;
    }
};

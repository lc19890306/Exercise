// Greedy solution - O(n) time and O(1) space complexity
// sum is the summation from the start to i
// if sum is less than 0, add sum to prev_sum, and then start from i + 1
// after scanning all the elements, if prev_sum + sum < 0, no matter where you start, the summation will be less than 0
// otherwise start is the final result
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty() || cost.empty() || gas.size() != cost.size())
            return -1;
        int n(gas.size()), prev_sum(0), sum(0), start(0);
        for (int i(0); i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                prev_sum += sum;
                sum = 0;
                start = i + 1;
            }
        }
        return prev_sum + sum < 0 ? -1 : start;
    }
};

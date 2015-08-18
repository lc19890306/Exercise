namespace Algo {
    template<typename ForwardIt, typename T>
    ForwardIt
    lower_bound(ForwardIt first, ForwardIt last, const T &value) {
        if (first == last) return last;
        auto count(distance(first, last));
        while (count > 0) {
            auto it(first);
            auto step(count >> 1);
            advance(it, step);
            if (*it > value)
                count = step;
            else {
                count -= step + 1;
                first = ++it;
            }
        }
        return first;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        auto delimit(Algo::lower_bound(nums.begin(), nums.end(), 0));
        if (delimit - 3 >= nums.begin() && delimit[-3] == 0)
            ret.emplace_back(vector<int>{0, 0, 0});
        if (delimit == nums.end()) {
            return ret;
        }
        unordered_set<int> non_positives(nums.begin(), delimit);
        unordered_set<int> positives(delimit, nums.end());
        for (auto i(nums.begin()); i != delimit; ++i) {
            if (0 == *i)
                break;
            if (i - 1 >= nums.begin() && i[-1] == *i)
                continue;
            for (auto j(delimit); j != nums.end(); ++j) {
                if (j - 1 >= delimit && j[-1] == *j)
                    continue;
                vector<int> tripet;
                auto target(-*i-*j);
                if (target == *i) {
                    if (i[1] == target) {
                        tripet.push_back(target);
                        tripet.push_back(target);
                        tripet.push_back(*j);
                        ret.emplace_back(tripet);
                    }
                }
                else if (target == *j) {
                    if (j[1] == target) {
                        tripet.push_back(*i);
                        tripet.push_back(target);
                        tripet.push_back(target);
                        ret.emplace_back(tripet);
                    }
                }
                else if (*i < target && target <= 0) {
                    if (non_positives.find(target) != non_positives.end()) {
                        tripet.push_back(*i);
                        tripet.push_back(target);
                        tripet.push_back(*j);
                        ret.emplace_back(tripet);
                    }
                }
                else if (*j < target) {
                    if (positives.find(target) != positives.end()) {
                        tripet.push_back(*i);
                        tripet.push_back(*j);
                        tripet.push_back(target);
                        ret.emplace_back(tripet);
                    }
                }
            }
        }
        return ret;
    }
};

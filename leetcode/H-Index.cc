// O(nlogn) time and O(1) space complexity
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i(0);
        for (; i < citations.size(); ++i)
            if (i + 1 > citations[i])
                return i;
        return i;
    }
};

// O(n) time and space complexity
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> hash_map(citations.size() + 1);
        for (auto &&citation : citations)
            if (citation > citations.size())
                ++hash_map.back();
            else
                ++hash_map[citation];
	// by adding hash_map[i] one by one, ret is the number of citations no less than i
        int ret(0);
        for (int i(hash_map.size() - 1); i >= 0; --i) {
            ret += hash_map[i];
            if (ret >= i)
                return i;
        }
        return ret;
    }
};

// Bit manipulation - O(n^2) at worst
class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs){return lhs.length() > rhs.length();});
        int ret(0), n(words.size());
        vector<int> mask(n);
        for (int i(0); i < n; ++i)
            for (auto &&c : words[i])
                mask[i] |= 1 << (c - 'a');
        for (int i(0); i < n - 1; ++i) {
            int l_i(words[i].length());
            if (l_i * l_i <= ret)
                break;
            for (int j(i); j < n; ++j) {
                int l_j(words[j].length());
                if (!(mask[i] & mask[j])) {
                    ret = max(ret, l_i * l_j);
                    break;
                }
            }
        }
        return ret;
    }
};

// Bit manipulation - O(n^2) at worst
class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs){return lhs.length() > rhs.length();});
        int ret(0), n(words.size());
        vector<bitset<26> > mask(n);
        for (int i(0); i < n; ++i)
            for (auto &&c : words[i])
                mask[i].set(c - 'a');
        for (int i(0); i < n - 1; ++i) {
            int l_i(words[i].length());
            if (l_i * l_i <= ret)
                break;
            for (int j(i); j < n; ++j) {
                int l_j(words[j].length());
                if ((mask[i] & mask[j]).none()) {
                    ret = max(ret, l_i * l_j);
                    break;
                }
            }
        }
        return ret;
    }
};

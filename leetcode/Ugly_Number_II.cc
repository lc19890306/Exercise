// heap + hashtable solution - O(nlogn) time complexity
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long> > q;
        unordered_set<long long> hash_table;
        q.push(1);
        hash_table.insert(1);
        while (--n > 0) {
            auto temp(q.top());
            q.pop();
            if (hash_table.find(temp * 2) == hash_table.end()) {
                q.push(temp * 2);
                hash_table.insert(temp * 2);
            }
            if (hash_table.find(temp * 3) == hash_table.end()) {
                q.push(temp * 3);
                hash_table.insert(temp * 3);
            }
            if (hash_table.find(temp * 5) == hash_table.end()) {
                q.push(temp * 5);
                hash_table.insert(temp * 5);
            }
        }
        return q.top();
    }
};

// DP solution - O(n) time complexity
// ret[i]: the (i-1)-th ugly number
// ret[0] = 1
// ret[1] = min(ret[0] * 2, ret[0] * 3, ret[0] * 5) = ret[0] * 2
// ret[2] = min(ret[1] * 2, ret[0] * 3, ret[0] * 5) = ret[0] * 3
// ret[3] = min(ret[1] * 2, ret[1] * 3, ret[0] * 5) = ret[1] * 2
// ret[4] = min(ret[2] * 2, ret[1] * 3, ret[0] * 5) = ret[0] * 5
// ret[5] = min(ret[2] * 2, ret[1] * 3, ret[1] * 5) = ret[2] * 2 = ret[1] * 3
// ret[6] = min(ret[3] * 2, ret[2] * 3, ret[1] * 5) = ret[1] * 5
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret(n);
        ret[0] = 1;
        for (int t2(0), t3(0), t5(0), i(1); i < n; ++i) {
            ret[i] = min(ret[t2] * 2, min(ret[t3] * 3, ret[t5] * 5));
            if (ret[i] == ret[t2] * 2) ++t2;
            if (ret[i] == ret[t3] * 3) ++t3;
            if (ret[i] == ret[t5] * 5) ++t5;
        }
        return ret[n - 1];
    }
};

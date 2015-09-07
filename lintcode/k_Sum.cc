// Easier to understand
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        if (target < 0)
            return 0;
        int ans[A.size() + 1][k + 1][target + 1];
	// in the first i numbers, find j numbers whose summation equals t
        for (int i(0); i <= A.size(); ++i)
            for (int j(0); j <= k; ++j)
                for (int t(0); t <= target; ++t)
		  // in the first i numbers, find 0 numbers whose summation equals 0, the result is undoubtedly 1
                    if (j == 0 && t == 0)
                        ans[i][j][t] = 1;
	// in the first i numbers, find j numbers whose summation equals t
	// if t < A[i - 1], then A[i - 1] won't be added into summation, the result should be the same as find j numbers whose summation equals t in the first i - 1 numbers
	// if t >= A[i - 1], then A[i - 1] will be added into summation, the result should be divided into two parts
	// 1. in the first i numbers, find j numbers whose summation equals t (summation doesn't contain A[i - 1])
	// 2. in the first i - 1 numbers, find j - 1 numbers whose summation equals t - A[i - 1] (summation contains A[i - 1])
                    else if (i != 0 && j != 0 && t != 0) {
                        ans[i][j][t] = ans[i - 1][j][t];
                        if (t >= A[i - 1])
                            ans[i][j][t] += ans[i - 1][j - 1][t - A[i - 1]];
                    }
                    else
                        ans[i][j][t] = 0;
        return ans[A.size()][k][target];
    }
};

// Still unable to understand...
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        if (target < 0)
            return 0;
        int ans[k + 1][target + 1];
        memset(ans, 0, sizeof(int) * (k + 1) * (target + 1));
        ans[0][0] = 1;
        for (int i(0); i < A.size(); ++i)
            for (int t(target); t > 0; --t)
                for (int j(1); j <= k; ++j)
                    if (t >= A[i])
                        ans[j][t] += ans[j - 1][t - A[i]];
        return ans[k][target];
    }
};

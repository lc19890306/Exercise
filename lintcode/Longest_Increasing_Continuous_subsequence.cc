class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if (A.size() < 3)
            return A.size();
        int ret(1), longest(1);
        bool ascending(true);
        for (int i(1); i < A.size(); ++i) {
            if (A[i] > A[i - 1])
	      // if trend is maintained, keep updating the global and local longest number
                if (ascending)
                    ret = max(ret, ++longest);
	    // if trend is changed, reset local longest number and switch the trend flag
                else {
                    longest = 2;
                    ascending = true;
                }
            else
	      // if trend is maintained, keep updating the global and local longest number
                if (!ascending)
                    ret = max(ret, ++longest);
	    // if trend is changed, reset local longest number and switch the trend flag
                else {
                    longest = 2;
                    ascending = false;
                }
        }
        return ret;
    }
};

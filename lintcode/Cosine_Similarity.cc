class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int inner_product(0);
        for (int i(0); i < A.size(); ++i)
            inner_product += (A[i] * B[i]);
        int sum_sqA(0);
        for (auto &&element : A)
            sum_sqA += (element * element);
        int sum_sqB(0);
        for (auto &&element : B)
            sum_sqB += (element * element);
        auto denominator(sqrt(sum_sqA) * sqrt(sum_sqB));
        return 0 == denominator ? 2.0000 : inner_product / denominator;
    }
};

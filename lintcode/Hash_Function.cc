class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long ret(0);
        for (auto &&c : key)
            ret = (ret * 33 + c) % HASH_SIZE;
        return ret;
    }
};

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        int ret(0);
        for (auto &&c : key)
            ret = (modMultiply(ret, 33, HASH_SIZE) + c) % HASH_SIZE;
        return ret;
    }
    
private:
    int modMultiply(int num, int base, int mod) {
        int ret(0), temp(num - mod);
        for (int i(0); i < base; ++i)
            ret += (ret + temp > 0 ? temp : num);
	// ret %= mod should be added in each iteration to make the final result less than mod
        return ret;
    }
};

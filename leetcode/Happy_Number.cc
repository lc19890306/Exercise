// hash table solution
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_table;
        int num(n);
        while (hash_table.find(num) == hash_table.end() && num != 1) {
            hash_table.insert(num);
            int new_num(0);
            while (num > 0) {
                auto temp(num % 10);
                new_num += temp * temp;
                num /= 10;
            }
            num = new_num;
        }
        return num == 1;
    }
};

// mathematical solution
// only 1 and 7 are happy
class Solution {
public:
    bool isHappy(int n) {
      // for n = abc, calculate a^2 + b^2 + c^2, until n becomes a digit
        while (n > 9) {
            int new_n(0);
            while (n > 0) {
                auto temp(n % 10);
                new_n += temp * temp;
                n /= 10;
            }
            n = new_n;
        }
        return n == 1 || n == 7;
    }
};

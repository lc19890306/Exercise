class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string integer, decimal;
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            integer.append("-");
	// use long because of case: INT_MIN / -1, abs(INT_MIN) still equals INT_MIN
        long n(labs(numerator)), d(labs(denominator));
	// use hashmap instead of hashtable because of case: 1 / 99 = 0.(01) and case: 1 / 6 = 0.1(6)
        unordered_map<int, int> hash_map;
        integer.append(to_string(n / d));
        n %= d;
        if (0 == n)
            return integer;
        integer.append(".");
        n *= 10;
        int i(-1);
        auto it(hash_map.find(n));
        while (it == hash_map.end()) {
            hash_map.insert(make_pair(n, ++i));
            auto quotient(n / d);
            decimal.append(to_string(quotient));
            n %= d;
            if (0 == n)
                return integer.append(decimal);
            n *= 10;
            it = hash_map.find(n);
        }
        decimal.insert(it->second, "(");
        return integer.append(decimal).append(")");
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return {};
        vector<int> ret;
        for (auto it(digits.rbegin()); it != digits.rend(); ++it) {
            ++*it;
            if (*it > 9)
                *it %= 10;
            else
                break;
        }
        if (digits[0] == 0)
            ret.push_back(1);
        for (auto &&digit : digits)
            ret.push_back(digit);
        return ret;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        if (digits.empty())
            return ret;
        int carry(1);
        for (auto it(digits.rbegin()); it != digits.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry)
            ret.push_back(1);
        copy(digits.begin(), digits.end(), back_inserter(ret));
        return ret;
    }
};

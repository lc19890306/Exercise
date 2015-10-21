class Solution {
public:
    string multiply(string num1, string num2) {
        BigNum a(num1), b(num2);
        return multiply(a, b);
    }
    
private:
    struct BigNum {
        BigNum(const string &str) {
            int i(str.length() - 4);
            for (; i >= 0; i -= 4)
                nums.push_back(strToNum(str.substr(i, 4)));
            i += 4;
            nums.push_back(strToNum(str.substr(0, i)));
        }
        
        int strToNum(const string &str) {
            int ret(0);
            for (auto &&c : str)
                ret = ret * 10 + c - '0';
            return ret;
        }
        
        vector<int> nums;
    };
    
    string multiply(const BigNum &a, const BigNum &b) {
        string ret;
        vector<vector<int> > products;
        for (int i(0); i < b.nums.size(); ++i)
            products.push_back(simple_multiply(a.nums, b.nums[i], i));
        vector<int> temp;
        if (!products.empty())
            temp = products[0];
        for (int i(1); i < products.size(); ++i)
            temp = add(temp, products[i]);
        for (auto &&num : temp)
            ret = to_string(num) + ret;
        return lstrip(ret, "0");
    }
    
    vector<int> simple_multiply(const vector<int> &a, const int &b, const int &padding) {
        vector<int> ret;
        for (int i(0); i < padding; ++i)
            ret.push_back(0);
        int carry(0);
        for (int i(0); i < a.size(); ++i) {
            auto res(a[i] * b + carry);
            ret.push_back(res % 10000);
            carry = res / 10000;
        }
        if (carry > 0)
            ret.push_back(carry);
        return ret;
    }
    
    vector<int> add(const vector<int> &a, const vector<int> &b) {
        vector<int> ret;
        int min_size(min(a.size(), b.size())), carry(0);
        for (int i(0); i < min_size; ++i) {
            auto res(a[i] + b[i] + carry);
            ret.push_back(res % 10000);
            carry = res / 10000;
        }
        if (min_size == a.size())
            for (int i(min_size); i < b.size(); ++i) {
                auto res(b[i] + carry);
                ret.push_back(res % 10000);
                carry = res / 10000;
            }
        else
            for (int i(min_size); i < a.size(); ++i) {
                auto res(a[i] + carry);
                ret.push_back(res % 10000);
                carry = res / 10000;
            }
        if (carry > 0)
            ret.push_back(carry);
        return ret;
    }
    
    string lstrip(const string &str, const string &targets) {
        auto left(str.find_first_not_of(targets));
        if (left == string::npos)
            return "0";
        return str.substr(left);
    }
    
    string to_string(const int &num) {
        string ret(std::to_string(num));
        while (ret.length() < 4)
            ret = "0" + ret;
        return ret;
    }
};

// Best solution - O(m * n) time complexity
class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.length() + num2.length(), '0');
        int carry, i, j;
        for (i = num1.length() - 1; i >= 0; --i) {
            carry = 0;
            for (j = num2.length() - 1; j >= 0; --j) {
                auto res((ret[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry);
                ret[i + j + 1] = res % 10 + '0';
                carry = res / 10;
            }
            ret[i + j + 1] = carry + '0';
        }
        auto first(ret.find_first_not_of("0"));
        return first == string::npos ? "0" : ret.substr(first);
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        string ret;
        char carry('0'), c_a, c_b;
        auto max_length(max(a.length(), b.length()));
        for (int i(0); i < max_length; ++i) {
            c_a = i < a.length() ? a[a.length() - i - 1] : '0';
            c_b = i < b.length() ? b[b.length() - i - 1] : '0';
            auto bit(addBit(c_a, c_b, carry));
            ret = bit + ret;
        }
        if ('1' == carry)
            ret = '1' + ret;
        return ret;
    }
    
private:
    char addBit(char a, char b, char &carry) {
        int num_a(a - '0'), num_b(b - '0'), num_carry(carry - '0');
        switch (num_a + num_b + num_carry) {
            case 0: return '0';
            case 1: carry = '0'; return '1';
            case 2: carry = '1'; return '0';
            default: return '1';
        }
    }
};

// Use this solution
class Solution {
public:
    string addBinary(string a, string b) {
        int diff(labs(a.length() - b.length()));
        string ret(diff, '0');
        ret.append(a.length() < b.length() ? a : b);
        int carry(0);
        string &longer(a.length() < b.length() ? b : a);
        for (int i(ret.length() - 1); i >= 0; --i) {
            int sum(longer[i] -'0' + ret[i] - '0' + carry);
            ret[i] = '0' + (sum & 1);
            carry = sum >> 1;
        }
        if (carry == 1)
            ret = '1' + ret;
        return ret;
    }
};

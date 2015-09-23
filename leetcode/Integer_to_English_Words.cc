unordered_map<int, string> hash_map{
    {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
    {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
    {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
    {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"},
    {1000000000, "Billion"}
};

class Solution {
public:
    string numberToWords(int num) {
      // 0
        if (!num)
            return "Zero";
        string ret;
        if (num / 1000000000 > 0) {
            ret += (hash_map[num / 1000000000] + " Billion ");
            num %= 1000000000;
        }
	// 123456789
        if (num / 1000000 > 0) {
            ret += (numberToWords(num / 1000000) + " Million ");
            num %= 1000000;
        }
	// 12345
        if (num / 1000 > 0) {
            ret += (numberToWords(num / 1000) + " Thousand ");
            num %= 1000;
        }
        if (num / 100 > 0) {
            ret += (hash_map[num / 100] + " Hundred ");
            num %= 100;
        }
	// 100
	// 12345
	// 12
        if (0 < num && num < 20) {
            ret += (hash_map[num] + " ");
            num /= 20;
        }
	// 123
        if (num / 10 > 0) {
            ret += (hash_map[num / 10 * 10] + " ");
            num %= 10;
        }
	// 4
        if (num > 0)
            ret += (hash_map[num]);
	// 100
        if (ret.back() == ' ')
            ret = ret.substr(0, ret.length() - 1);
        return ret;
    }
};

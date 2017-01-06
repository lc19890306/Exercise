class Solution {
public:
    int lengthOfLastWord(string s) {
        auto right(s.find_last_not_of(' '));
        if (right == string::npos)
            return 0;
	// test case: "world"
	// find_last_of returns npos (-1), so right - (-1) is still correct
        return right - s.find_last_of(' ', right);
    }
};

// A more discreet solution compared with the above one
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto right(s.find_last_not_of(' '));
        if (right == string::npos)
            return 0;
        auto left(s.find_last_of(' ', right));
        return left == string::npos ? right + 1 : right - left;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream input(s);
        string word;
        while (input >> word);
        return word.length();
    }
};

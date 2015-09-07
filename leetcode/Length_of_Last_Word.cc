class Solution {
public:
    int lengthOfLastWord(string s) {
        auto right(s.find_last_not_of(' '));
        if (right == string::npos)
            return 0;
        return right - s.find_last_of(' ', right);
    }
};

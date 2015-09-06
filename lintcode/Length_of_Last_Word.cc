class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        auto right(s.find_last_not_of(" "));
        if (right == string::npos)
            return 0;
        auto left(s.substr(0, right + 1).find_last_of(" "));
        if (left == string::npos)
            return right + 1;
        else
            return right - left;
    }
};

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        istringstream input(s);
        string word;
        while (input >> word);
        return word.length();
    }
};

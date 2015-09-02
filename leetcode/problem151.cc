class Solution {
public:
    void reverseWords(string &s) {
        istringstream input(s);
        string word;
        s.clear();
        input >> s;
        while (input >> word)
            s = word + " " + s;
    }
};

// In-place reverse with O(1) memory and O(n) time
class Solution {
public:
    void reverseWords(string &s) {
        auto last(s.find_first_not_of(" "));
        if (last != string::npos)
            s.erase(s.begin(), s.begin() + last);
        else {
            s.clear();
            return;
        }
        auto first(s.find_last_not_of(" "));
        s.erase(s.begin() + first + 1, s.end());
        reverse(s.begin(), s.end());
        first = 0;
        last = 0;
        while (true) {
            first = s.find_first_not_of(" ", last);
            if (first == string::npos)
                break;
            if (first - last > 1) {
                s.erase(last + 1, first - last - 1);
                first = last + 1;
            }
            last = s.find_first_of(" ", first);
            if (last == string::npos)
                last = s.length();
            reverse(s.begin() + first, s.begin() + last);
        }
    }
};

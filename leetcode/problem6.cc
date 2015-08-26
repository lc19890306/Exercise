// 0, 1, 2, ..., numRows - 2, numRows - 1, numRows - 2, ..., 2, 1, 0, 1, 2, ...
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length())
            return s;
        vector<string> vec(numRows);
        int i(0);
        bool inc(true);
        for (auto &&c : s) {
            vec[i] += c;
            if (i == numRows - 1) inc = false;
            if (i == 0) inc = true;
            if (inc) ++i;
            else --i;
        }
        string ret;
        for (auto &&str : vec)
            ret += str;
        return ret;
    }
};

// For each row, calculate corresponding index in string s and add the character one by one
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length())
            return s;
        string ret;
	// In border rows, the step between each index
        int borderRowStep((numRows - 1) << 1);
        for (int i(0); i != numRows; ++i) {
            bool large(true);
	    // In inside rows, the large and small step between each index by turn
            int insideRowLargeStep((numRows - 1 - i) << 1);
            int insideRowSmallStep(borderRowStep - insideRowLargeStep);
	    // LargeStep == 0 means this row is the bottom border row
    	    if (insideRowLargeStep == 0)
                large = false;
            for (int j(i); j < s.size();) {
                ret.push_back(s[j]);
                if (large)
                    j += insideRowLargeStep;
                else
                    j += insideRowSmallStep;
		// If any of large and small step is 0, this row is a border ow, and the flag will be set to a value which makes each step greater than 0
	        if (insideRowLargeStep * insideRowSmallStep != 0)
                    large ^= 1;
            }
        }
        return ret;
    }
};

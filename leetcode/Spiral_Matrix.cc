class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty() || matrix.front().empty())
            return ret;
	// left, right, top, and bottom 4 bounds
	// t should start from 1 because 0 is unreachable upwards
        int b(matrix.size()), r(matrix.front().size()), last(b * r), l(0), t(1);
        Dir dir(RW);
        for (int i(0), row(0), col(0); i < last; ++i) {
            ret.push_back(matrix[row][col]);
            switch (dir) {
                case RW: {
                    ++col;
                    if (col == r) {
                        --col;
                        ++row;
                        --r;	// decrement right bound
                        dir = DW;
                    }
                }
                break;
                case DW: {
                    ++row;
                    if (row == b) {
                        --row;
                        --col;
                        --b;
                        dir = LW;
                    }
                }
                break;
                case LW: {
                    --col;
                    if (col < l) { // l - 1 actually
                        ++col;
                        --row;
                        ++l;
                        dir = UW;
                    }
                }
                break;
                case UW: {
                    --row;
                    if (row < t) { // t - 1 actually
                        ++row;
                        ++col;
                        ++t;
                        dir = RW;
                    }
                }
                break;
                default:
                break;
            }
        }
        return ret;
    }
    
private:
    typedef enum {RW, DW, LW, UW} Dir;
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int last(n * n + 1);
        Dir dir(RW);
        vector<vector<int> > ret(n, vector<int>(n));
        for (int i(1), row(0), col(0); i < last; ++i) {
            ret[row][col] = i;
            switch (dir) {
                case RW: {
                    ++col;
		    // if reaches border or existing element
                    if (col == n || ret[row][col]) {
                        ++row;
                        --col;
                        dir = DW;
                    }
                }
                break;
                case DW: {
                    ++row;
                    if (row == n || ret[row][col]) {
                        --row;
                        --col;
                        dir = LW;
                    }
                }
                break;
                case LW: {
                    --col;
                    if (col == -1 || ret[row][col]) {
                        ++col;
                        --row;
                        dir = UW;
                    }
                }
                break;
                case UW: {
                    --row;
                    if (row == -1 || ret[row][col]) {
                        ++row;
                        ++col;
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
  // 4 directions
    typedef enum {RW, DW, LW, UW} Dir;
};

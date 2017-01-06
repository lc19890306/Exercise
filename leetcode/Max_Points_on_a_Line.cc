/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> stat;
        int ret(1), n(points.size());
        // if no points input, return 0
        if (!n)
            return 0;
        for (int i(0); i < n; ++i) {
            // must clear hash_map in each iteration
            stat.clear();
            // initialize duplicate as 1 to take points[i] itself into consideration
            int cur_max(0), duplicate(1);
            for (int j(i + 1); j < n; ++j) {
                // if duplicated
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    ++duplicate;
                    continue;
                }
                // must consider the infinity slope (e.g. x = 0)
                float key(points[j].x == points[i].x ? numeric_limits<float>::infinity() : static_cast<float>(points[j].y - points[i].y) / (points[j].x - points[i].x));
                ++stat[key];
                // update cur_max in current iteration
                cur_max = max(cur_max, stat[key]);
            }
            // update ret after current iteration
            ret = max(ret, cur_max + duplicate);
        }
        return ret;
    }
};

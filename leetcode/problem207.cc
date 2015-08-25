#include <vector>
#include <deque>

using namespace std;

struct Info {
    int indegree;
    deque<int> courses;
    Info() : indegree(0) {}
};

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Info> graph(numCourses);
        for (auto &&pair : prerequisites) {
            ++graph[pair.first].indegree;
            graph[pair.second].courses.push_back(pair.first);
        }
        int counter(2);
        bool cycle;
        while (counter-- > 0) {
            cycle = false;
            for (auto &&info : graph) {
                if (info.indegree == 0) {
                    while (!info.courses.empty()) {
                        --graph[info.courses.front()].indegree;
                        info.courses.pop_front();
                    }
                }
                if (info.indegree > 0)
                    cycle = true;
            }
        }
        return !cycle;
    }

int main() {
  vector<pair<int, int> > p = {{0, 1}, {0, 2}, {1, 2}};
  auto ret(canFinish(3, p));
  return 0;
}

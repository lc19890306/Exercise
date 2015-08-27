// DFS - search for cycles, if found, cannot finish all courses
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph.resize(numCourses);
        checked.resize(numCourses);
        cycle_free.resize(numCourses);
        for (auto &&pair : prerequisites)
            graph[pair.second].push_back(pair.first);
        while (true) {
            auto it(find(checked.begin(), checked.end(), false));
            if (it == checked.end())
                return true;
            auto course(distance(checked.begin(), it));
            if (cycleExists(course))
                return false;
        }
    }
  
private:
    bool cycleExists(const size_t &course) {
        if (checked[course])
            return true;
        checked[course] = true;
        if (graph[course].empty()) {
            cycle_free[course] = true;
            return false;
        }
        for (auto &&neighbor : graph[course])
            if (!cycle_free[neighbor] && cycleExists(neighbor))
                return true;
        cycle_free[course] = true;
        return false;
    }
    
    vector<vector<int> > graph;
    vector<bool> checked;
    vector<bool> cycle_free;
};

// BFS - topology sort + find cycle, if there still remain some nodes after topology sort ends, cycle exisits
class Solution {
public:
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
        while (true) {
            bool cycle(false), changed(false);
            for (auto &&info : graph) {
                if (info.indegree == 0) {
                    while (!info.courses.empty()) {
                        --graph[info.courses.front()].indegree;
                        info.courses.pop_front();
                        changed = true;
                    }
                }
                if (info.indegree > 0)
                    cycle = true;
            }
            if (!changed)
                return !cycle;
        }
    }
};

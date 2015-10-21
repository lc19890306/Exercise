// BFS solution - topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ret;
        vector<pair<int, vector<int> > > courses(numCourses);
        for (auto &&pair : prerequisites) {
            ++courses[pair.first].first;
            courses[pair.second].second.push_back(pair.first);
        }
        while (true) {
            bool changed(false);
            for (int i(0); i < courses.size(); ++i)
                if (!courses[i].first) {
                    courses[i].first = -1;
                    ret.push_back(i);
                    for (auto &&following : courses[i].second)
                        --courses[following].first;
                    changed = true;
                }
            if (!changed)
                break;
        }
        return ret.size() == numCourses ? ret : vector<int>();
    }
};

// Recursive DFS solution - topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        cycle_free.resize(numCourses);
        visited.resize(numCourses);
        graph.resize(numCourses);
        for (auto &&pair : prerequisites)
            graph[pair.second].push_back(pair.first);
        for (int i(0); i < numCourses; ++i) {
            if (!visited[i])
                if (!findOrder(i))
                    return vector<int>();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
private:
    bool findOrder(int course) {
        if (visited[course])
            return false;
        visited[course] = true;
        if (graph[course].empty()) {
	  // if has no neighbor, it is cycle free
            cycle_free[course] = true;
            ret.push_back(course);
            return true;
        }
        for (auto &&following : graph[course])
            if (!cycle_free[following] && !findOrder(following))
                return false;
	// if all the neighbors are cycle free, it is cycle free
        cycle_free[course] = true;
        ret.push_back(course);
        return true;
    }
    
    vector<int> cycle_free;
    vector<vector<int> > graph;
    vector<bool> visited;
    vector<int> ret;
};

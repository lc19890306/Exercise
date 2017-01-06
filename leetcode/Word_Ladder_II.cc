// BFS + DFS backtracking solution
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> s1{beginWord}, s2{endWord};
        unordered_map<string, vector<string> > neighbors;
        path.push_back(beginWord);
        findLadders(s1, s2, wordList, neighbors);
        findPaths(beginWord, endWord, neighbors);
        return ret;
    }
    
private:
    void findLadders(
        unordered_set<string> &s1, 
        unordered_set<string> &s2, 
        unordered_set<string> &wordList,
        unordered_map<string, vector<string> > &neighbors) {
            if (s1.empty())
                return;
            for (auto &&word : s1)
                wordList.erase(word);
            for (auto &&word : s2)
                wordList.erase(word);
            unordered_set<string> s3;
            bool reached(false);
            for (auto it(s1.begin()); it != s1.end(); ++it) {
                auto word(*it);
                for (auto &&c : word) {
                    auto temp(c);
                    for (c = 'a'; c <= 'z'; ++c) {
                        if (s2.find(word) != s2.end()) {
                            reached = true;
                            neighbors[*it].push_back(word);
                        }
                        else if (!reached && wordList.find(word) != wordList.end()) {
                            s3.insert(word);
                            neighbors[*it].push_back(word);
                        }
                    }
                    c = temp;
                }
            }
            if (!reached)
                findLadders(s3, s2, wordList, neighbors);
        }

    void findPaths(
        string beginWord,
        string endWord,
        unordered_map<string, vector<string> > &neighbors) {
            if (beginWord == endWord) {
                ret.push_back(path);
                return;
            }
            for (auto &&neighbor : neighbors[beginWord]) {
                path.push_back(neighbor);
                findPaths(neighbor, endWord, neighbors);
                path.pop_back();
            }
        }

    vector<string> path;
    vector<vector<string> > ret;
};

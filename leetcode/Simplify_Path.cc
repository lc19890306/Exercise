class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q;
        string str;
        for (auto &&c : path) {
            if ('/' == c) {
                if ("/.." == str) {
                    if (!q.empty())
                        q.pop_back();
                }
                else if ("/." != str && "/" != str && !str.empty())
                    q.push_back(str);
                str.clear();
            }
            str += c;
        }
        if ("/.." == str) {
            if (!q.empty())
                q.pop_back();
        }
        else if ("/" != str && "/." != str)
            q.push_back(str);
        str.clear();
        for (auto &&s : q)
            str += s;
        return str.empty() ? "/" : str;
    }
};

// Best solution
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string str;
        istringstream input(path);
        while (getline(input, str, '/')) {
            if (str.empty() || "." == str)
                continue;
            if (".." == str) {
                if (!vec.empty())
                    vec.pop_back();
            }
            else
                vec.push_back(str);
        }
        str.clear();
        for (auto &&s : vec)
            str += ("/" + s);
        return str.empty() ? "/" : str;
    }
};

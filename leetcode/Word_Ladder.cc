// BFS solution - O(n*k) time complexity where n is the number of words and k is the maximum length of all the words
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord.empty() || endWord.empty() || beginWord.length() != endWord.length())
            return 0;
        queue<pair<string, int> > q;
        q.push(make_pair(beginWord, 1));
        wordList.insert(endWord);
        while (!q.empty()) {
            auto word(q.front().first);
            auto len(q.front().second);
            q.pop();
            if (word == endWord)
                return len;
            findNeighbor(word, wordList, q, len);
        }
        return 0;
    }
    
private:
    void findNeighbor(string word, unordered_set<string> &wordList, queue<pair<string, int> > &q, int len) {
        for (int i(0); i < word.length(); ++i) {
            char c(word[i]);
            for (int j(0); j < 26; ++j) {
                if ('a' + j == c)
                    continue;
                word[i] = 'a' + j;
                if (wordList.find(word) != wordList.end()) {
                    q.push(make_pair(word, len + 1));
                    wordList.erase(word);
                }
            }
            word[i] = c;
        }
    }
};

// Double-end BFS solution - O(n*k) time complexity
// Faster than single-end BFS solution
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord.empty() || endWord.empty() || beginWord.length() != endWord.length())
            return 0;
        unordered_set<string> s1{beginWord}, s2{endWord};
        return ladderLength(s1, s2, wordList, 1);
    }
    
private:
    int ladderLength(unordered_set<string> &s1, unordered_set<string> &s2, unordered_set<string> &wordList, int len) {
        if (s1.empty())
            return 0;
        unordered_set<string> s3;
	// word cannot be lvalue or rvalue reference!!!
        for (auto word : s1) {
            for (auto &&c : word) {
                auto temp(c);
                for (c = 'a'; c <= 'z'; ++c) {
                    if (c == temp)
                        continue;
                    if (s2.find(word) != s2.end())
                        return len + 1;
                    if (wordList.find(word) != wordList.end()) {
                        wordList.erase(word);
                        s3.insert(word);
                    }
                }
                c = temp;
            }
        }
        return s2.size() <= s3.size() ? ladderLength(s2, s3, wordList, len + 1) : ladderLength(s3, s2, wordList, len + 1);
    }
};

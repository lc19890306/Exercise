class WordDictionary {
public:

    WordDictionary() : root(new TrieNode()) {}

    ~WordDictionary() {
        destroy(root);
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        auto node(root);
        for (auto &&c : word) {
            int i(c - 'a');
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return find(root, word, 0);
    }
    
private:
    struct TrieNode {
        TrieNode() : isWord(false) {
            for (auto &&child : children)
                child = nullptr;
        }
        
        bool isWord;
        TrieNode *children[26];
    };
    
    bool find(TrieNode *node, const string &word, int begin) {
        if (!node)
            return false;
        auto p(node);
        for (int i(begin); i < word.length() && p; ++i) {
            if (word[i] != '.') {
                int idx(word[i] - 'a');
                if (!p->children[idx])
                    return false;
                p = p->children[idx];
            }
            else {
                for (auto &&child : p->children)
                    if (find(child, word, i + 1))
                        return true;
                return false;
            }
        }
        return p->isWord;
    }
    
    void destroy(TrieNode *node) {
        if (!node)
            return;
        for (auto &&child : node->children)
            destroy(child);
        delete node;
    }
    
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

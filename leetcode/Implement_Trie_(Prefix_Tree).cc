// O(n) time complexity
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false) {
        for (auto &&c : children)
            c = nullptr;
    }
    
    bool isWord;
    TrieNode *children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        destroy(root);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto node(root);
        for (auto &&c : word) {
            int i(c - 'a');
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto node(find(word));
        return node ? node->isWord : false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix);
    }

private:
    TrieNode * find(const string &word) {
        auto node(root);
        for (int i(0); i < word.length() && node; ++i)
            node = node->children[word[i] - 'a'];
        return node;
    }
    
    void destroy(TrieNode *node) {
        if (!node)
            return;
        for (auto &&child : node->children)
            destroy(child);
        delete node;
    }

    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

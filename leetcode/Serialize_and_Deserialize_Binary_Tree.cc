/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto node(q.front());
            q.pop();
            if (!node) {
                ret.append("#").append(" ");
                continue;
            }
            ret.append(to_string(node->val)).append(" ");
            q.push(node->left);
            q.push(node->right);
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      // use deque because we have to access to both the front and the back
      // use a boolean to mark whether left child exists
        deque<pair<TreeNode *, bool> > q;
        istringstream input(data);
        string word;
        TreeNode *root = nullptr;
        while (input >> word) {
            if (q.empty()) {
                q.push_back(make_pair(word == "#" ? nullptr : new TreeNode(stoi(word)), false));
                root = q.front().first;
            }
            else {
                while (!q.front().first)
                    q.pop_front();
                if (!q.front().second) {
                    q.front().first->left = word == "#" ? nullptr : new TreeNode(stoi(word));
                    q.front().second = true;
                    q.push_back(make_pair(q.front().first->left, false));
                }
                else {
                    q.front().first->right = word == "#" ? nullptr : new TreeNode(stoi(word));
                    q.push_back(make_pair(q.front().first->right, false));
                    q.pop_front();
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

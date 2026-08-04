/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> exists;
        return dfs(node, exists);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& exists) {
        if(node == NULL) return NULL;
        if(exists.count(node)) return exists[node]; //return the copy

        Node* copy = new Node(node->val);
        exists[node] = copy;

        for(auto it : node->neighbors) {
            copy->neighbors.push_back(dfs(it, exists));
        }

        return copy;
    }
};

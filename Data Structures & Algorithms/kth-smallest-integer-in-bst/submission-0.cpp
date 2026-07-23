/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void populate(TreeNode* root, priority_queue<int, vector<int>, greater<int>> &min_heap) {
        if(!root) return;
        populate(root->left, min_heap);
        min_heap.push(root->val);
        populate(root->right, min_heap);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        populate(root, min_heap);
        for(int i = 0; i < k - 1; i++) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};

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
    int findDiameter(TreeNode* root, int &ans) {
        if(!root) return 0;

        int leftAns = findDiameter(root->left, ans);
        int rightAns = findDiameter(root->right, ans);

        ans = max(ans, leftAns + rightAns);

        return 1 + max(leftAns, rightAns);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        findDiameter(root, ans);
        return ans;
    }
};

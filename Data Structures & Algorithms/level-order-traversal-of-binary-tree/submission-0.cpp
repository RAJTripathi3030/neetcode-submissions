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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if(!root) return ans;

        TreeNode* curr = root;
        q.push(curr);

        while(!q.empty()) {
            vector<int> temp;
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                temp.push_back(front->val);
                q.pop();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int idx = 0;

        solve(subset, ans, nums, idx);

        return ans;
    }

    void solve(vector<int>& subset, vector<vector<int>>& ans, const vector<int>& nums, int idx) {
        if(idx >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        solve(subset, ans, nums, idx+1);
        subset.pop_back();
        solve(subset, ans, nums, idx+1);
    }
};

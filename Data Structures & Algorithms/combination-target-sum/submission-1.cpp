class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(curr, ans, nums, target, 0);
        return ans;
    }

    void solve(vector<int>& curr, vector<vector<int>>& ans, 
               vector<int>& nums, int target, int idx) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0 || idx >= nums.size()) {
            return;
        }

        // Take element
        curr.push_back(nums[idx]);
        solve(curr, ans, nums, target - nums[idx], idx);
        // Not take element
        curr.pop_back();
        solve(curr, ans, nums, target, idx+1);
    }
};

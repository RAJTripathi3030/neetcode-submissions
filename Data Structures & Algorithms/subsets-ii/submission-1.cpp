class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> tempAns;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        solve(tempAns, temp, nums, 0);

        vector<vector<int>> ans(tempAns.begin(), tempAns.end());
        return ans;
    }

    void solve(set<vector<int>>& tempAns, vector<int>& temp, vector<int>& nums, int idx) {
        if(idx >= nums.size()) {
            tempAns.insert(temp);
            return;
        }

        // Take
        temp.push_back(nums[idx]);
        solve(tempAns, temp, nums, idx+1);
        // Not Take
        temp.pop_back();
        while(idx < nums.size()-1 && nums[idx] == nums[idx + 1]) idx++;
        solve(tempAns, temp, nums, idx+1);
    }
};

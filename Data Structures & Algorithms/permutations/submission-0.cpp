class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) {
            return {{}};
        }

        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(temp);
        vector<vector<int>> ans;

        for(const auto& p : perms) {
            for(int i = 0; i <= p.size(); i++) {
                vector<int>p_cpy = p;
                p_cpy.insert(p_cpy.begin() + i, nums[0]);
                ans.push_back(p_cpy);
            }
        }

        return ans;
    }
};

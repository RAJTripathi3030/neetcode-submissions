class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = 0;
        int streak = 0;
        int i = 0;
        int expected_ele = nums[i];

        sort(nums.begin(), nums.end());

        while(i < nums.size()) {
            if(nums[i] != expected_ele) {
                expected_ele = nums[i];
                streak = 0;
            }
            while(i < nums.size() && expected_ele == nums[i]) {
                i++;
            }
            streak++;
            expected_ele++;
            res = max(res, streak);
        }

        return res;
    }
};

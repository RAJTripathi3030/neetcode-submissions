class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> tMap;

        for(int i = 0; i < nums.size(); i++) {
            int mapVal = target - nums[i];
            tMap[mapVal] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            auto it = tMap.find(nums[i]);
            if(it != tMap.end() && it->second != i) {
                return {i, it->second};
            }
        }

        return ans;
    }
};

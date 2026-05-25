class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>mp;
        int len = 0;
        for(auto ele : nums) {
            if(!mp[ele]) {
                mp[ele] = mp[ele - 1] + mp[ele + 1] + 1;
                mp[ele - mp[ele - 1]] = mp[ele];
                mp[ele + mp[ele + 1]] = mp[ele];
                len = max(len, mp[ele]);
            }
        }
        return len;
    }
};

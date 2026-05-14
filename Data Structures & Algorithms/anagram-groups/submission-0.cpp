class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tMap;
        vector<vector<string>> ans;
        
        for(auto str : strs) {
            int wordArr[26] = {0};
            for(auto ch : str) {
                wordArr[ch - 'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++) {
                key += wordArr[i] + '#';
            }
            tMap[key].push_back(str);
        }

        for(auto const& [key, group] : tMap) {
            ans.push_back(group);
        }

        return ans;
    }
};

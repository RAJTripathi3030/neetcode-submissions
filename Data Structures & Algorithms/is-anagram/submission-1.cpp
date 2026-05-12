class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> mapForS;
        unordered_map<char, int> mapForT;

        for(auto c : s) {
            mapForS[c] += 1;
        }
        for(auto c : t) {
            mapForT[c] += 1;
        }

        for(auto const& [key, _] : mapForS) {
            if(mapForS[key] != mapForT[key]){
                return false;
            }
        }

        return true;
    }
};

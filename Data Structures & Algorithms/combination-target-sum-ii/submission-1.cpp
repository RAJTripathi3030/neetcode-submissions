class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(), arr.end());
        solve(ans, curr, 0, arr, t);

        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& curr, int idx, const vector<int>& arr, int target) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(target < 0 || idx >= arr.size()) {
            return;
        }

        curr.push_back(arr[idx]);
        solve(ans, curr, idx+1, arr, target - arr[idx]);
        curr.pop_back();
        while(idx + 1 < arr.size() && arr[idx] == arr[idx+1]) idx++;
        solve(ans, curr, idx+1, arr, target);
    }
};

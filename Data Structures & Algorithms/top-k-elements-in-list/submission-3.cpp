class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        for(auto ele : nums) {
            nums_map[ele]++;
        }

        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > nums_pq;
        for(auto& kv : nums_map) {
            nums_pq.push({kv.second, kv.first});

            if(nums_pq.size() > k) nums_pq.pop();
        }

        vector<int> ans;
        while(!nums_pq.empty()) {
            ans.push_back( nums_pq.top().second );
            nums_pq.pop();
        }

        return ans;
    }
};

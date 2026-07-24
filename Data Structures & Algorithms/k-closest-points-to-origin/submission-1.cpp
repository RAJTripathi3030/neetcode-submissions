class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>, 
            greater<pair<int, vector<int>>>> pq;

        for(int i = 0; i < points.size(); i++) {
            int dx = points[i][0] - 0;
            int dy = points[i][1] - 0;
            int dist = (dx * dx) + (dy * dy);
            pair<int, vector<int>> p = {dist, points[i]};
            pq.push(p);
        }

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

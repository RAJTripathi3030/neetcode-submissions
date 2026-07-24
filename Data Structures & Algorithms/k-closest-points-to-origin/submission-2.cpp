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
            // square is a monotonically increasing function hence no 
            // need to compute squares as the squared distance will 
            // also be far from the origin in a similar ratio.
            // Hence, comparing squared distances gives the 
            // same ordering and is faster
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

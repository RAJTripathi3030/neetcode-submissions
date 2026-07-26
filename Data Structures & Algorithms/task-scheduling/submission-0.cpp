class Solution {
   public:  // A,A,A,B,C
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequencyMap;
        for (int i = 0; i < tasks.size(); ++i) {
            frequencyMap[tasks[i]]++;
        }

        vector<pair<int, char>> arr;  // [[3,A], [1,B], [1,C]]
        for (auto it : frequencyMap) {
            arr.push_back({it.second, it.first});
        }
        vector<char> processed;
        int time{0};

        while (arr.size() != 0) {
            int bestTaskIndex = -1;
            // Objective of following loop is to find out the best
            // executable task currently.
            for (int i = 0; i < arr.size(); i++) {
                bool ok = true;

                if (find(processed.begin() + (max(0, time - n)), processed.end(),
                         arr[i].second) != processed.end()) {
                    ok = false;
                }
                if(!ok) continue;
                if (bestTaskIndex == -1 || arr[bestTaskIndex].first < arr[i].first) {
                    bestTaskIndex = i;
                }
            }
            time++;
            char curr = '#';
            if (bestTaskIndex != -1) {
                curr = arr[bestTaskIndex].second;
                arr[bestTaskIndex].first--;
                if (arr[bestTaskIndex].first == 0) {
                    arr.erase(arr.begin() + bestTaskIndex);
                }
            }
            processed.push_back(curr);
        }

        return time;
    }
};

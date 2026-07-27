class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> taskFreq;

        for(int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        int time = 0;
        // for(auto it : freq){cout<<it<<", ";}

        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                taskFreq.push(freq[i]);
            }
        }
        queue<pair<int, int>> process;

        while(taskFreq.size() != 0 || !process.empty()) {
            time++;
            
            if(taskFreq.empty()) {
                time = process.front().second;
            } else {
                int cnt = taskFreq.top() - 1;
                taskFreq.pop();
                if(cnt != 0) process.push({cnt, time + n});
            }

            if(!process.empty() && process.front().second == time) {
                taskFreq.push(process.front().first);
                process.pop();
            }
        }

        return time;
    }
};

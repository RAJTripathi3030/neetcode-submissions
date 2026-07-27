class Twitter {
public:
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
    
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweetList;
        priority_queue<pair<int, int>> topTweetsHeap;

        // Iterate in tweet list of userId and put them in heap
        for(auto it : tweetMap[userId]) {
            topTweetsHeap.push({it[0], it[1]});
        }

        // Now it's time to insert the tweets of the followers
        for(auto followee : followMap[userId]) {
            for(auto it : tweetMap[followee]) {
                topTweetsHeap.push({it[0], it[1]});
            }
        }

        // Now take out top 10 tweets from the max heap
        for(int i = 0; i < 10 && !topTweetsHeap.empty() ; i++) {
            int tweetID = topTweetsHeap.top().second;
            topTweetsHeap.pop();
            if(find(tweetList.begin(), tweetList.end(), tweetID) == tweetList.end())
                tweetList.push_back(tweetID);
        }

        return tweetList;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

class Twitter {
private:
    // Store tweets: userId -> list of (timestamp, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    // Store follow relationships: userId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followers;
    
    // Global timestamp to order tweets
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // Priority queue to store tweets by timestamp, min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Fetch user's own tweets
        for (auto &tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10) {
                pq.pop();
            }
        }
        
        // Fetch tweets from followees
        for (int followeeId : followers[userId]) {
            for (auto &tweet : tweets[followeeId]) {
                pq.push(tweet);
                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }
        
        // Collect the tweets from the priority queue
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        // The tweets are in ascending order, we need the most recent first
        reverse(result.begin(), result.end());
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
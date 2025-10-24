class Twitter {
public:
    // Tweet data: (time, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;
    // Follower -> Followees
    unordered_map<int, unordered_set<int>> following;
    int timeStamp;

    Twitter() {
        timeStamp = 0;
    }

    // Post a new tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    // Retrieve the 10 most recent tweets in user's news feed
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;  // max heap based on time
        // Include user's own tweets
        if (tweets.count(userId)) {
            for (auto &t : tweets[userId])
                pq.push(t);
        }
        // Include followed users' tweets
        for (auto &f : following[userId]) {
            if (tweets.count(f)) {
                for (auto &t : tweets[f])
                    pq.push(t);
            }
        }

        vector<int> res;
        int count = 0;
        while (!pq.empty() && count < 10) {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }

    // Follower starts following followee
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    // Follower unfollows followee
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

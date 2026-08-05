class Twitter {
public:
    unordered_map<int, vector<vector<int>>> postMpp;
    unordered_map<int, priority_queue<vector<int>>> feedMpp;
    unordered_map<int, vector<int>> followMpp;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        vector<int> post = {time++, tweetId, userId};
        postMpp[userId].push_back(post);

        feedMpp[userId].push(post);

        for (auto &follower : followMpp[userId]) {
            feedMpp[follower].push(post);
        }

        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;

        int ptr = 0;
        
        stack<vector<int>> st;

        while (!feedMpp[userId].empty() && ptr < 10) {
            vector<int> post = feedMpp[userId].top();
            feedMpp[userId].pop();
            st.push(post);
            newsFeed.push_back(post[1]);
            ptr++;
        }
        
        while(!st.empty()) {
            vector<int> post = st.top();
            st.pop();
            feedMpp[userId].push(post);
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        auto it = find(followMpp[followeeId].begin(), followMpp[followeeId].end(), followerId);
        if (it != followMpp[followeeId].end())
            return;
        
        followMpp[followeeId].push_back(followerId);

        for (auto &post : postMpp[followeeId]) {
            feedMpp[followerId].push(post);
        }

        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;

        auto it = find(followMpp[followeeId].begin(), followMpp[followeeId].end(), followerId);
        if (it == followMpp[followeeId].end())
            return;
        
        followMpp[followeeId].erase(it);

        stack<vector<int>> st;

        while (!feedMpp[followerId].empty()) {
            vector<int> post = feedMpp[followerId].top();
            feedMpp[followerId].pop();
            if (post[2] != followeeId) {
                st.push(post);
            }
        }

        while (!st.empty()) {
            vector<int> post = st.top();
            st.pop();
            feedMpp[followerId].push(post);
        }

        return;
    }
};

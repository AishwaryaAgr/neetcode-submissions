class Twitter {
public:
    map<int,set<int> > following;
    map<int,vector<pair<int,int> > > tweets;
    int time;
    Twitter() {
        map<int,vector<pair<int,int> > > t;
        map<int,set<int> > t2;
        following  = t2;
        tweets = t;
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(tweets.find(userId) == tweets.end()){
            tweets[userId] = vector<pair<int,int> > ();
        }
        tweets[userId].push_back(make_pair(time++,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> s;

        if(following.find(userId) != following.end()){
            s = following[userId];
        }
        s.insert(userId);

        priority_queue<pair<int,int> > feed;
        for(auto x : s){
            int sz = 0;
            int last = tweets[x].size()-1;
            for(int i=last;i>=0;i--){
                feed.push(tweets[x][i]);
                sz++;
                if(sz == 10)break;
            }
        }
        vector<int> ans;
        int res = 0;

        while(feed.size() && res<10){
            ans.push_back(feed.top().second);
            feed.pop();
            res++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(following.find(followerId) == following.end()){
            following[followerId] = {};
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId) != following[followerId].end()){
            following[followerId].erase(followeeId);
        } 
    }
};

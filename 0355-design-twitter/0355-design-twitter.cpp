
/*
resource priority-queue pair: https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/

intuisi: 
- buat map follow<int, set<int>> utk mengetahui user memfoloow siapa saja.
- buat map tweet<int, vector<pair<int, int>> untuk menyimpan tweeet user, isi tweet {timestamp, tweetId}
- timestamp dibuat sbg attribute dari class. int timestamp =0 , yg selalu diincrement +=1 setiap kali ada tweet baru. timestamp diset ke tweet baru user.
- untuk getNewsFeed: 
 -  buat priorityQueue , fetch tweet user dan push ke priorityQueue, shg priorityQueue berisi most recent tweet by user
 - fetch user lain yg difollow user, lalu setiap user yg difollow difetch postnya, dan push ke priorityQueue, 
 - pop 10 highest value dari priorityQueue  dan push ke vector res, untuk mendapatkan 10 most recent tweet 
- maxHeap berdasarkan first element dari pair (timestamp )







*/
class Twitter {
private: 
    unordered_map<int, set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;
    long long time;

public:
    Twitter() {
        time  = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        for (auto tweet = tweets[userId].begin(); tweet != tweets[userId].end(); ++tweet){
            maxHeap.push(*tweet);
        }
        for (auto userFlw = follows[userId].begin(); userFlw != follows[userId].end(); ++userFlw){
            int userFollowed = *userFlw;
            for (auto tweet = tweets[userFollowed].begin(); tweet != tweets[userFollowed].end() ; ++tweet) {
                maxHeap.push(*tweet);
            }
        }

        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10 ){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
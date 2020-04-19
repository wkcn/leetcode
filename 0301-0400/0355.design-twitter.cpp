#include "common.h"

struct Msg {
  int time;
  int tid;
};

int T = 0;

class User {
public:
    void follow(int id) {
        follows.insert(id);
    }
    void unfollow(int id) {
        follows.erase(id);
    }
    void post(int tid) {
        tweets.push_front({T++, tid});
        if (tweets.size() > 10) tweets.pop_back();
    }
    set<int> follows;
    list<Msg> tweets;
};

using PType = pair<list<Msg>*, list<Msg>::iterator>; 
struct PT_CMP {
  bool operator()(PType &a, PType &b) {
    return (a.second)->time < (b.second)->time;
  }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
      users[userId].post(tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
      vector<int> ans;
      priority_queue<PType, vector<PType>, PT_CMP> its;
      User &u = users[userId];
      if (u.tweets.size())
        its.push({&(u.tweets), u.tweets.begin()});
      for (int uid : u.follows) {
        User &fo = users[uid];
        if (fo.tweets.size())
          its.push({&(fo.tweets), fo.tweets.begin()});
      }
      for (int t = 0; t < 10 && !its.empty(); ++t) {
        auto [li, p] = its.top(); its.pop();
        ans.push_back(p->tid);
        ++p;
        if (p != li->end()) its.push({li, p});
      }
      return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
      if (followerId != followeeId)
        users[followerId].follow(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].unfollow(followeeId);
    }
private:
    map<int, User> users;
};

int main() {
  Twitter twitter;

  // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
  twitter.postTweet(1, 5);

  // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
  PRINT_ARRAY(twitter.getNewsFeed(1));

  // 用户1关注了用户2.
  twitter.follow(1, 2);

  // 用户2发送了一个新推文 (推文id = 6).
  twitter.postTweet(2, 6);

  // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
  // 推文id6应当在推文id5之前，因为它是在5之后发送的.
  PRINT_ARRAY(twitter.getNewsFeed(1));

  // 用户1取消关注了用户2.
  twitter.unfollow(1, 2);

  // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
  // 因为用户1已经不再关注用户2.
  PRINT_ARRAY(twitter.getNewsFeed(1));

  return 0;
}

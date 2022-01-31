#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
using pii = pair<int, int>;
class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
      if (timestamp >= cur_timestamp_) {
        cur_timestamp_ = timestamp;
        cur_price_ = price;
      }
      rec_[timestamp] = price;
      max_pq_.emplace(price, timestamp);
      min_pq_.emplace(price, timestamp);
    }
    
    int current() {
      return cur_price_;
    }
    
    int maximum() {
      return _get_pq_latest(max_pq_);
    }
    
    int minimum() {
      return _get_pq_latest(min_pq_);
    }
    template <typename PQ_T>
    int _get_pq_latest(PQ_T &pq) {
      while (!pq.empty()) {
        auto [p, t] = pq.top();
        if (rec_[t] == p) return p;
        pq.pop();
      }
      return 0;
    }
private:
    priority_queue<pii> max_pq_;
    priority_queue<pii, vector<pii>, greater<pii>> min_pq_;
    unordered_map<int, int> rec_;
    int cur_price_;
    int cur_timestamp_; 
};
#elif SOLUTION == 2

class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
      cur_timestamp_ = max(cur_timestamp_, timestamp);
      auto p = rec_.find(timestamp);
      if (p == rec_.end()) {
        se_.insert(price);
        rec_[timestamp] = price;
      } else if (p->second != price) {
        auto t = se_.find(p->second);
        se_.erase(t);
        p->second = price;
      }
    }
    
    int current() {
      return rec_[cur_timestamp_];
    }
    
    int maximum() {
      return *se_.rbegin();
    }
    
    int minimum() {
      return *se_.begin();
    }
private:
    multiset<int> se_;
    unordered_map<int, int> rec_;
    int cur_timestamp_;
};

#endif


int main() {
  return 0;
}

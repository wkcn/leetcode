#include "common.h"

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : times_(times) {
      int best_idx = -1;
      int best_score = 0;
      unordered_map<int, int> cnts;
      wins_.resize(persons.size());
      for (int i = 0; i < persons.size(); ++i) {
        int s = ++cnts[persons[i]];
        if (s >= best_score) {
          best_idx = persons[i];
          best_score = s;
        }
        wins_[i] = best_idx;
      }
    }
    
    int q(int t) {
      auto p = upper_bound(times_.begin(), times_.end(), t) - 1;
      return wins_[p - times_.begin()];
    }
private:
    vector<int> wins_;
    vector<int> times_;
};

int main() {
  vector<int> persons{0, 1, 1, 0, 0, 1, 0}, times{0, 5, 10, 15, 20, 25, 30};
  vector<int> qs{3, 12, 25, 15, 24, 8};
  TopVotedCandidate tv(persons, times);
  for (int q: qs) {
    cout << tv.q(q) << endl;
  }
  return 0;
}

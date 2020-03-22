// 其实从一个点出发，只要斜率一样就能共线了！
#include "common.h"

struct Record {
  vector<int> ids;
  int cnt;
  Record() : cnt(0) {

  }
};

using LL = long long;

LL gcd(LL a, LL b) {
  LL r;
  do {
    r = a % b;
    a = b;
    b = r;
  } while (r != 0);
  return a;
}

class Solution {
public:
  vector<int> bestLine(vector<vector<int>>& points) {
    // (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
    // (y2 - y1) x + (x1 - x2) y = (y2 - y1) * x1 + (x1 - x2) * y1
    int n = points.size();
    map<array<LL, 3>, Record> ABC_ma;

    int best = 0;
    vector<int> ans;

    // 如果A与B和A与C都在一条直线上，那么B与C也在该条直线上
    for (int i = 0; i < n; ++i) {
      vector<int> &pi = points[i];
      int dup = 0; // 与pi位置相同的点数
      ABC_ma.clear();
      int local_best = 0;
      vector<int> local_ans;
      for (int j = i + 1; j < n; ++j) {
        vector<int> &pj = points[j];
        LL A = (LL)pj[1] - pi[1];
        LL B = (LL)pj[0] - pi[0];
        if (A == 0 && B == 0) {
          // pi与pj相同
          ++dup;
          if (local_ans.empty()) local_ans = {i, j};
          continue;
        }
        LL C = A * pi[0] + B * pi[1]; 

        if (A == 0) {
          if (C == 0) {
            B = 1;
          } else {
            LL g = gcd(B, C);
            B /= g;
            C /= g;
          }
        } else if (B == 0) {
          if (C == 0) {
            A = 1;
          } else {
            LL g = gcd(A, C);
            A /= g;
            C /= g;
          }
        } else {
          // A != 0 and B != 0
          LL g = gcd(A, B);
          if (C == 0) {
            A /= g;
            B /= g;
          } else {
            LL w = gcd(g, C);
            A /= w;
            B /= w;
            C /= w;
          }
        }

        Record &r = ABC_ma[{A, B, C}];
        if (r.cnt == 0) {
          r.ids = {i, j};
        }
        ++r.cnt;

      }
      update_ans(ABC_ma, local_best, local_ans);
      local_best += dup;
      if (local_best > best) {
        ans = std::move(local_ans);
        best = local_best;
      }
    }

    return ans;
  }
  template <typename T>
  void update_ans(map<T, Record> &ma, int &best, vector<int> &ans) {
    for (auto &p : ma) {
      Record &r = p.second;
      if (r.cnt > best) {
        best = r.cnt;
        ans = std::move(r.ids);
      } else if (p.second.cnt == best) {
        // 如果穿过相同数量的点
        if (r.ids[0] < ans[0] || (r.ids[0] == ans[0] && r.ids[1] < ans[1])) {
          ans = std::move(r.ids);
        }
      }
    }
  }
};

ostream& operator<<(ostream& os, const pair<float, float> &p) {
  os << "k = " << p.first << ", " << "b = " << p.second;
  return os;
} 

int main() {
  vector<vector<int> > points;
  INPUT_ARRAY2D(points);
  PRINT_ARRAY(Solution().bestLine(points));
  return 0;
}

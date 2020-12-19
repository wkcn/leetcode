#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // a / b / c
        // (a / b) / c
        // a / (b / c) = a / b * c
        // a / (b / c) / d = a / b * c / d
        // a / (b / (c / d)) = a / (b / c * d) = a / b * c / d
        // a / b / (c / d) = a / b / c * d
        // a / (b / c / d) = a / b * c * d
        // a / (b / c / d / e / f) = a / b * c * d * e * f
        // 可不可以不除以b, 不行
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < (int)nums.size() - 1; ++i) {
            ans += to_string(nums[i]) + '/';
        }
        ans += to_string(nums.back()) + ')';
        return ans;
    }
};

#elif SOLUTION == 2

class Solution {
public:
  string optimalDivision(vector<int>& nums) {
    map<pair<int, int>, State> states;
    std::function<State&(int, int)> F = [&](int start, int end) -> State& {
      pair<int, int> key{start, end};
      auto [it, is_new] = states.insert({key, {}});
      if (!is_new) return it->second;
      if (end - start == 1) return it->second = State(nums[start]);
      // 不需要特殊处理size == 2的情况
      // if (end - start == 2) return it->second = State(nums[start], nums[start + 1]);
      // 枚举分割点, [start, u), [u, end)
      State &s = it->second;
      s.mi = FLT_MAX;
      s.ma = FLT_MIN;
      // 注意u < end
      for (int u = start + 1; u < end; ++u) {
        State &left = F(start, u);
        State &right = F(u, end);
        float ma = left.ma / right.mi;
        float mi = left.mi / right.ma;
        bool sr = u == end - 1;
        if (ma > s.ma) {
          s.ma = ma;
          s.ma_exp = left.ma_exp + '/' + (sr ? "" : "(") + right.mi_exp + (sr ? "" : ")");
        }
        if (mi < s.mi) {
          s.mi = mi;
          s.mi_exp = left.mi_exp + '/' + (sr ? "" : "(") + right.ma_exp + (sr ? "" : ")");
        }
      }
      return s;
    };
    return F(0, nums.size()).ma_exp;
  }
private:
  struct State {
    float mi, ma;
    string mi_exp, ma_exp;
    State() {}
    State(int v) {
      mi = ma = v;
      mi_exp = ma_exp = to_string(v);
    }
    State(int a, int b) {
      mi = ma = (float)a / b;
      mi_exp = ma_exp = to_string(a) + '/' + to_string(b); 
    }
  };
};

#endif

int main() {
  vector<int> nums = {1000, 100, 10, 2};
  cout << Solution().optimalDivision(nums) << endl;
  return 0;
}

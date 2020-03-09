// [HARD]
// 树状数组：https://www.cnblogs.com/xenny/p/9739600.html
/*
C[1] = A[1];                                                      0001 k=0
C[2] = A[1] + A[2];                                               0010 k=1
C[3] = A[3];                                                      0011 k=0
C[4] = A[1] + A[2] + A[3] + A[4];                                 0100 k=2
C[5] = A[5];                                                      0101 k=0
C[6] = A[5] + A[6];                                               0110 k=1
C[7] = A[7];                                                      0111 k=0
C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];`    1000 k=3

C[i] = A[i - 2k+1] + A[i - 2k+2] + ... + A[i];   //k为i的二进制中从最低位到高位连续零的长度
SUMi = C[i] + C[i-2k1] + C[(i - 2k1) - 2k2] + .....；
2^k = i&(i^(i-1));
2^k = i&(-i);
 */

#include "common.h"

#define SOLUTION 2

#if SOLUTION == 1
// 这里A[i](i>=1)存储的是数字i-1的个数
// C[i]用来查找小于或等于x的值的个数
class StreamRank {
public:
    StreamRank() : C(50002, 0){
    }

    void track(int x) {
      ++x; // 下标需要大于等于1
      while (x <= 50001) {
        ++C[x]; // k=1
        x += x & (-x); // += lowbit
      }
    }

    int getRankOfNumber(int x) {
      int res = 0;
      ++x;
      while (x > 0) {
        res += C[x];
        x -= x & (-x);
      }
      return res;
    }
private:
    vector<int> C;
};
#elif SOLUTION == 2

struct MyTreeNode {
  int val;
  int cnt; // 记录子树中以及自己，值小于等于val的节点数
  MyTreeNode *left, *right;
  MyTreeNode(int x) :val(x), cnt(1), left(NULL), right(NULL) {}
};

class StreamRank {
public:
    StreamRank() : root(nullptr) {
    }

    void track(int x) {
      MyTreeNode **p = &root;
      while (*p) {
        if (x == (*p)->val) {
          ++((*p)->cnt);
          break;
        } else if (x < (*p)->val) {
          ++((*p)->cnt);
          p = &((*p)->left);
        } else {
          p = &((*p)->right);
        }
      }
      if (!(*p)) {
        *p = new MyTreeNode(x);
      }
    }

    int getRankOfNumber(int x) {
      MyTreeNode *r = root;
      int res = 0;
      while (r) {
        if (r->val == x) {
          res += r->cnt;
          break;
        } else if (r->val < x) {
          res += r->cnt;
          r = r->right;
        } else {
          // x < r->val
          r = r->left;
        }
      }
      return res;
    }
private:
    MyTreeNode *root;
};

#endif

int main() {
  StreamRank r;
  r.track(1);
  cout << r.getRankOfNumber(2) << endl; //1
  r.track(2);
  r.track(10);
  r.track(4);
  cout << r.getRankOfNumber(2) << endl; // 2
  cout << r.getRankOfNumber(5) << endl; // 3
  cout << r.getRankOfNumber(11) << endl; //4
  return 0;
}

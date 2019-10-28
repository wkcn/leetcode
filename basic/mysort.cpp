/*
 * Reference:
 * std::sort
 * https://blog.csdn.net/qq_35440678/article/details/80147601
 * the performance of memcpy
 * https://blog.csdn.net/alangdangjia/article/details/12259149
 */
#include <future>
#include "common.h"
using namespace std;

using sort_func_t = void (*)(vector<int> &);
map<string, sort_func_t> sort_funcs;

#define AddFunc(func) sort_funcs[#func]=(func); 

template <typename T>
void itemcpy(T* dest, T* source, int n) {
  for (int i = 0; i < n; ++i) {
    *(dest++) = *(source++);
  }
}

#if 1
void itemcpy(int* dest, int* source, int n) {
  memcpy(dest, source, sizeof(int) * n);
}
#endif

void bubble_sort(vector<int> &v) {
  const int len = v.size();
  for (int i = 1; i < len; ++i) {
    bool ordered = true;
    for (int j = 0; j < len - i; ++j) {
      if (v[j] > v[j+1]) {
        swap(v[j], v[j+1]); 
        ordered = false;
      }
    }
    if (ordered) break;
  }
}

void insert_sort(vector<int> &v) {
  const int len = v.size();
  for (int i = 1; i < len; ++i) {
    int t = v[i];
    int j;
    for (j = i - 1; j >= 0; --j) {
      if (v[j] > t) {
        v[j + 1] = v[j];
      } else break;
    }
    v[j + 1] = t;
  }
}

void _in_merge_sort(vector<int> &v, vector<int> &tmp, int start, int end) {
  if (end - start <= 1) return;
  int mid = start + (end - start) / 2;
  _in_merge_sort(v, tmp, start, mid);
  _in_merge_sort(v, tmp, mid, end);
  int i = start, j = mid, k = start;
  itemcpy(&tmp[start], &v[start], mid - start);
  while (i < mid || j < end) {
    while (i < mid && (j >= end || tmp[i] <= v[j])) v[k++] = tmp[i++];
    while (j < end && (i >= mid || v[j] <= tmp[i])) v[k++] = v[j++];
  }
}

void merge_sort(vector<int> &v) {
  vector<int> tmp(v.size());
  _in_merge_sort(v, tmp, 0, v.size());
}

void _in_merge_sort_multi_thread(vector<int> &v, vector<int> &tmp, int start, int end) {
  if (end - start <= 1) return;
  int mid = start + (end - start) / 2;
  if (end - start > 100000) {
    auto left_thread = std::async(_in_merge_sort_multi_thread, std::ref(v), std::ref(tmp), start, mid);
    auto right_thread = std::async(_in_merge_sort_multi_thread, std::ref(v), std::ref(tmp), mid, end);
    left_thread.get();
    right_thread.get();
  } else {
    _in_merge_sort(v, tmp, start, mid);
    _in_merge_sort(v, tmp, mid, end);
  }
  int i = start, j = mid, k = start;
  itemcpy(&tmp[start], &v[start], mid - start);
  while (i < mid || j < end) {
    while (i < mid && (j >= end || tmp[i] <= v[j])) v[k++] = tmp[i++];
    while (j < end && (i >= mid || v[j] <= tmp[i])) v[k++] = v[j++];
  }
}

void merge_sort_multi_thread(vector<int> &v) {
  vector<int> tmp(v.size());
  _in_merge_sort_multi_thread(v, tmp, 0, v.size());
}

void max_heapify(vector<int> &v, int p, const int len) {
  while (1) {
    int son = p * 2 + 1;
    if (son >= len) return;
    // choose maximum son
    if (son + 1 < len && v[son] < v[son + 1]) ++son;
    if (v[p] >= v[son]) return;
    swap(v[p], v[son]);
    p = son;
  }
}

void heap_sort(vector<int> &v) {
  const int len = v.size();
  for (int i = len / 2 - 1; i >= 0; --i) {
    max_heapify(v, i, len);
  }
  for (int i = len - 1; i > 0; --i) {
    swap(v[0], v[i]);
    max_heapify(v, 0, i);
  }
}

void _in_quick_sort(vector<int> &v, const int start, const int end) {
  if (end - start <= 1) return;
  int key = v[start];
  int i = start, j = end - 1;
  while (i < j) {
    while (i < j && v[j] >= key) --j;
    v[i] = v[j];
    while (i < j && v[i] <= key) ++i;
    v[j] = v[i];
  }
  v[i] = key;
  _in_quick_sort(v, start, i);
  _in_quick_sort(v, i + 1, end);
}

void quick_sort(vector<int> &v) {
  _in_quick_sort(v, 0, v.size());
}

// it is slower than quick_sort (recursive version)
void quick_sort_nonrecursive(vector<int> &v) {
  queue<pair<int, int> > q;
  q.push({0, v.size() - 1});
  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();
    int i = p.first;
    int j = p.second;
    if (j - i <= 0) continue;
    int key = v[i];
    while (i < j) {
      while (i < j && v[j] >= key) --j;
      v[i] = v[j];
      while (i < j && v[i] <= key) ++i;
      v[j] = v[i];
    }
    v[i] = key;
    q.push({p.first, i - 1});
    q.push({i + 1, p.second});
  }
}

void TestFunctions() {
  int n = 2000;
  vector<int> data(n);
  for (int i = 0; i < n; ++i) {
    data[i] = rand();
  }
  vector<int> gt = data;
  {
    Timer timer("baseline");
    timer.tic();
    sort(gt.begin(), gt.end());
    timer.toc();
  }
  for (auto p : sort_funcs) {
    vector<int> tmp = data;
    Timer timer(p.first);
    timer.tic();
    p.second(tmp);
    timer.toc();
    bool success = true;
    for (int i = 0; i < n; ++i) {
      if (tmp[i] != gt[i]) {
        success = false;
        break;
      }
    }
    cout << p.first << ": " << (success ? "success" : "fail") << endl;
  }
}

int main() {
  srand(39);
  AddFunc(bubble_sort);
  AddFunc(insert_sort);
  AddFunc(merge_sort);
  AddFunc(merge_sort_multi_thread);
  AddFunc(heap_sort);
  AddFunc(quick_sort);
  AddFunc(quick_sort_nonrecursive);
  TestFunctions();
  return 0;
}

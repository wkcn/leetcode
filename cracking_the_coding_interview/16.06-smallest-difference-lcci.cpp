/*
 * 使用二分搜索`lower_bound`跳过不必要的比较。
`lower_bound`返回数组中从小到大第一个大于等于目标值的索引。
假设`a[ai] < b[bi]`, 在数组a的区间[ai+1, alen)上进行二分搜索后得到新的`ai'`.
数组a在区间`[0, ai')`中的元素都小于`b[bi]`, 在区间`[ai', alen)`中的元素都大于或等于`b[bi]`.
`ai'`可能等于`alen`，即数组a中的所有元素都小于`b[bi]`.
元素`a[ai']`必定存在，它是数组a中小于`b[bi]`的最大值，也就是数组A中小于`b[bi]`的元素集合里离`b[bi]`最近的元素，因此需要计算`abs(a[ai'] - b[bi])`.
同理处理`a[ai] > b[bi]`。
 */
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        const int alen = a.size(), blen = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ai = 0, bi = 0;
        long long best = INT64_MAX;
        long long absdiff;
        while (ai < alen && bi < blen) {
            if (a[ai] == b[bi]) return 0;
            absdiff = abs((long long)a[ai] - (long long)b[bi]);
            if (absdiff < best) best = absdiff;
            if (a[ai] < b[bi]) {
                ai = lower_bound(a.begin()+ai+1, a.end(), b[bi]) - a.begin();
                absdiff = abs((long long)a[ai-1] - (long long)b[bi]);
                if (absdiff < best) best = absdiff;
            } else {
                bi = lower_bound(b.begin()+bi+1, b.end(), a[ai]) - b.begin();
                absdiff = abs((long long)a[ai] - (long long)b[bi-1]);
                if (absdiff < best) best = absdiff;
            }
        }
        return best;
    }
};

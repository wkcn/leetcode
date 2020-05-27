class Solution {
public:
 
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int len1 = nums1.size();
    const int len2 = nums2.size();
    const int tot = len1 + len2;
    function<int(int, int, int)> F;
    F = [&](int i, int j, int k) {
        if (i >= len1) return nums2[j + k];
        if (j >= len2) return nums1[i + k];
        if (k == 0) return min(nums1[i], nums2[j]);
        // [i, len1), len1 - i
        // [j, len2), len2 - j
        // k >= 1
        int i_offset = min(k / 2, len1 - i - 1); // i_offset >= 0
        int j_offset = max(0, min(k - 1 - i_offset, len2 - j - 1));
        return nums1[i + i_offset] < nums2[j + j_offset] ?
            F(i + i_offset + 1, j, k - i_offset - 1) :
            F(i, j + j_offset + 1, k - j_offset - 1);
    };
    if (tot % 2) {
        // odd
        return F(0, 0, tot / 2);
    }
    return (F(0, 0, tot / 2 - 1) + F(0, 0, tot / 2)) / 2.0;
}

};

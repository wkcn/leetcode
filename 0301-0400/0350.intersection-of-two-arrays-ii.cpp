class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        // nums1.size() <= nums2.size()
        if (nums1.empty()) return {};
        sort(nums1.begin(), nums1.end());
        const int BLOCK_SIZE = 512;

        const int len1 = nums1.size(), len2 = nums2.size();
        const int num_block = (len2 + BLOCK_SIZE - 1) / BLOCK_SIZE;
        vector<int> out;
        vector<bool> used(len1, false); // 要记住已经使用的数字
        for (int b = 0; b < num_block; ++b) {
            const int start = b * BLOCK_SIZE;
            const int end = min(len2, start + BLOCK_SIZE);
            sort(nums2.begin() + start, nums2.begin() + end);
            int i = 0;
            for (int j = start; j < end; ++j) {
                while (i < len1 && (used[i] || nums1[i] < nums2[j])) ++i;
                if (i >= len1) break;
                if (!used[i] && nums1[i] == nums2[j]) {
                    out.push_back(nums2[j]);
                    used[i] = true;
                    ++i; // 需要更新！
                }
            }
        }
        return out;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        // nums1.size() <= nums2.size()
        if (nums1.empty()) return {};
        unordered_map<int, int> ma;
        for (int x : nums1) ++ma[x];
        vector<int> out;
        for (int x : nums2) {
            auto p = ma.find(x);
            if (p == ma.end() || p->second == 0) continue;
            --(p->second);
            out.push_back(x);
        }
        return out;
    }
};

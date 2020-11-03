class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int left = -1, right = -1;
        int ma = INT32_MIN;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] >= ma) ma = array[i];
            else right = i;
        }
        int mi = INT32_MAX;
        for (int i = (int)array.size() - 1; i >= 0; --i) {
            if (array[i] <= mi) mi = array[i];
            else left = i;
        }
        return {left, right};
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 1, hi = arr.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                lo = mid + 1;
            } else if (arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]){
                hi = mid;
            } else {
                return mid;
            }
        }
        return lo;
    }
};

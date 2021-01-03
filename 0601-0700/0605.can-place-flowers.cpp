class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) continue;
            if (i - 1 >= 0 && flowerbed[i - 1]) continue;
            if (i + 1 < flowerbed.size() && flowerbed[i + 1]) continue;
            if (--n <= 0) return true;
            flowerbed[i] = 1;
        }
        return n <= 0;
    }
};

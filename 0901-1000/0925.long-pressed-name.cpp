class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                ++i; ++j;
            } else {
                if (i == 0) return false;
                if (name[i - 1] == typed[j]) {
                    ++j; // 长按
                } else {
                    return false;
                }
            }
        }
        if (i < name.size()) return false;
        while (j < typed.size()) {
            if (name.back() == typed[j]) ++j;
            else return false;
        }
        return j >= typed.size();
    }
};

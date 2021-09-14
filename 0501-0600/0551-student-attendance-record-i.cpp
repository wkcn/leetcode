class Solution {
public:
    bool checkRecord(string s) {
        int cnt = 0;
        int ab = 0;
        for (char c : s) {
            switch (c) {
                case 'L':
                    if (++cnt >= 3) return false;
                    break;
                case 'A':
                    if (++ab >= 2) return false;
                case 'P':
                    cnt = 0;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool checkRecord(string s) {
        int num_A = 0;
        int num_L = 0;
        for (char &c : s) {
            switch (c) {
                case 'L':
                    ++num_L;
                    if (num_L >= 3) return false;
                    break;
                case 'A':
                    ++num_A;
                default:
                    num_L = 0;
            }
        }
        return num_A <= 1;
    }
};

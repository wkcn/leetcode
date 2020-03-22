class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int sc[4] = {0};
        int gc[4] = {0};
        int right = 0;
        for (int i = 0; i < 4; ++i) {
            if (solution[i] == guess[i]) {
                ++right;
            } else {
                ++sc[cid(solution[i])];
                ++gc[cid(guess[i])];
            }
        }
        int w = 0;
        for (int i = 0; i < 4; ++i) {
            w += min(gc[i], sc[i]);
        }
        return {right, w};
    }
    inline int cid(char c) {
        switch (c) {
            case 'R':
                return 0;
            case 'Y':
                return 1;
            case 'G':
                return 2;
        }
        return 3;
    }
};

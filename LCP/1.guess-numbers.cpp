class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        const int N = guess.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (guess[i] == answer[i]) ++ans;
        }
        return ans;
    }
};

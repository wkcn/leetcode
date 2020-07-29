// [TODO] 试着用归纳法证明一下
class Solution {
public:
    bool divisorGame(int N) {
        // 输掉游戏的条件：N <= 1
        return N % 2 == 0;
    }
};

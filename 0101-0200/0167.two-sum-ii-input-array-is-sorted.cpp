class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int su = numbers[i] + numbers[j];
            if (su == target) break;
            su < target ? ++i : --j;
        }
        return {i + 1, j + 1};
    }
};

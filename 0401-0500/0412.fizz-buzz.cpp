class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
            else if (i % 3 == 0) ans.push_back("Fizz");
            else if (i % 5 == 0) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            ans.push_back({});
            if (i % 3 == 0) ans.back() += ("Fizz");
            if (i % 5 == 0) ans.back() += ("Buzz");
            if (ans.back().empty()) ans.back() = (to_string(i));
        }
        return ans;
    }
};

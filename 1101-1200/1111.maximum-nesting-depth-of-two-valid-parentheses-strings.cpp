class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        /*
        左括号 ( 的下标编号与嵌套深度的奇偶性相反，也就是说：

下标编号为奇数的 (，其嵌套深度为偶数，分配给 B；

下标编号为偶数的 (，其嵌套深度为奇数，分配给 A。

右括号 ) 的下标编号与嵌套深度的奇偶性相同，也就是说：

下标编号为奇数的 )，其嵌套深度为奇数，分配给 A；

下标编号为偶数的 )，其嵌套深度为偶数，分配给 B。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/you-xiao-gua-hao-de-qian-tao-shen-du-by-leetcode-s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
         */
         vector<int> ans;
         for (int i = 0; i < seq.size();++i) {
             ans.push_back((i&1) ^ (seq[i] == '('));
         }
         return ans;
    }
};

# Leetcode Solution

## Progress
[[Problem List]](./problems.md)

## 1. Two Sum

二重循环遍历

## 2. Add Two Numbers

链表求和，哨兵节点

## 3. Longest Substring Without Repeating Characters

最长没有重复字符的子序列

记录各字符最近一次出现的位置

## 4. Median of Two Sorted Arrays

求两有序数列的中位数，可泛化为求两有序数列的第k位数，二分法

## 5. Longest Palindromic Substring

最长回文子串，补符号，记忆

## 6. ZigZag Conversion

观察规律

## 7. Reverse Integer

翻转整数

## 8. String to Integer

解析字符串

## 9. Palindrome Number

回文数字

## 10. Regular Expression Matching

动态规划，列出转换方程即可，注意初值
记T[i][j] = 是否S[0:i]和P[0:j]匹配
再分类讨论，其中pattern *分为0, 1, more三种类型
```
0: i不变, j+1
1: i+1, j+1
more: i+1, j不变
```

## 11. Container with Most Water

条形图最大面积，归纳法证明

## 12. Integer to Roman

找规律

## 13. Roman to Integer

找规律

## 14. Longest Common Prefix

最长公共前缀

## 15. 3Sum

O(n^2logn): 先对数组排序

选两个数，找第3个数

去重复数不会降低渐进复杂度

upper_bound的使用

O(n^2): 先对数组排序

三个数下标i, j, k

确定i, 调整j, k

去重做跳表能加速

## 16. 3Sum Closest

参考15. 3Sum

## 17. Letter Combinations of a Phone Number

枚举，这里用进位法，也可以翻倍逐个输入

要注意空的输入

## 18. 4Sum

使用递归算法
使用估计结果是否存在的方法能将时间从48ms降低到12ms
减少加法计算次数也能加速，说明编译器没有充分优化

## 19. Remove Nth Node From End of List

移除单链表中倒数第n个元素，使用固定距离的双链表，注意要用dummy结点

## 20. Valid Parenthess

括号匹配, 栈

## 21. Merge Two Sorted Lists

有序链表Merge

## 22. Generate Parenthess

递归生成

## 23. Merge K Sorted Lists 

有序链表Merge, 使用堆heap

## 24. Swap Nodes in Pairs

单向链表，翻转相邻节点，dummy node

## 25. Reverse Nodes in k-Group

单向链表，每次翻转k个节点, 注意指针的改变

## 26. Remove Duplicates from Sorted Array

有序数组去重

## 29. Divide Two Integers

不使用乘除法实现int32除法

注意临界值, 删除多余操作

## 27. Remove Element

去除特定数字

## 31. Next Permutation

字典序

## 35. Search Insert Position

返回元素在有序数组中的插入位置

不变式

lower_bound: xx < target [lo, hi) target <= yy

upper_bound: xx <= target [lo, hi) target < yy

## 37. Sudoku Solver

不知道为什么，我写的递归方法并不快, 可能分配内存太多了, 或者哪里写得太慢了

## 38. Count and Say

用队列优化, 找规律

## 39. Combination Sum

递归，回溯，Solution比Solution2递归次数少，也更快

## 41. First Missing Positive

由于所求的数字是正数，可以将正数与数组下标对应。用数组下标记录数字是否存在。

## 43. Multiply Strings

大数相乘, 存储已经计算的结果

`for_each`用法

## 50. Pow(x, n)

Power幂乘

第一种方法因为多算了一次`base = base * base`, 所以变慢了

## 53. Maximum Subarray

最大和子串，动态规划

记串为s, a[i]为[0, i]串中子串的最大和

有a[i] = max(s[i], s[i] + a[i-1]) 

## 55. Jump Game

找规律，覆盖，注意边界

## 56. Merge Intervals

合并区间

考虑两区间包含，相交，分离三种情况

## 58. Length of Last Word

简单题，需要注意末尾为空格的情况

## 59. Spiral Matrix II

while(n--) 没有 while(n-- > 0) 好

## 62. Unique Paths

简单动归，一维数组即可解决

## 63. Unique Paths II

简单动归，一维数组即可解决
注意用unsigned long long存储避免溢出
最大值是多少呢？
100x100: 463,1081,1694,8371,8960
long long: 922,3372,0368,5477,5807
unsigned long long: 1844,6744,0737,0955,1615

## 64. Minimum Path Sum

简单动归

## 66. Plus One

注意999的情况就好

## 67. Add Binary

注意最低位的index是size - 1, 而且两个数字的长度不一定相同

## 69. Sqrt(x)

二分搜索，见basic/bisearch.cpp
注意lower_bound和upper_bound的定义！
mid * mid <= x 会溢出，mid <= x / mid就不会
注意特殊条件，如sqrt(0), sqrt(1), sqrt(2)

## 70. Climbing Stairs

爬梯子问题，简单动态规划

## 83. Remove Duplicates from Sorted List

有序链表去重，简单题

## 88. Merge Sorted Array

归并排序，空间问题

正序，**反序**遍历

可以O(n)时间实现

## 91. Decode Ways

解码，动态规划，两个变量就可以记录状态。

注意初值设定，特殊情况

## 94. Binary Tree Inorder Traversal

二叉树中序遍历，递归算法使用栈Stack

## 98. Validate Binary Search Tree

验证是否二叉搜索树

涉及到无效值时，可以用指针处理，即指针为nullptr是代表无效值

std::tuple的使用

DFS和BFS对二叉树的遍历：
https://leetcode.com/problems/validate-binary-search-tree/solution/

二叉树的遍历方式：
VLR, LVR, LRV, level


## 100. Same Tree

判断是同样的树

## 101. Symmetric Tree

判断树是否对称, 注意比较顺序

## 110. Balanced Binary Tree

判断平衡树，递归求子树深度

## 121. Best Time to Buy and Sell Stock

股票，动态规划，注意输入为空的情况
如果当前股票为历史最低价，那么它一定不是best, 这样可以减少4ms.
预先用一个变量保存数组长度，也能减少4ms

## 122. Best Time to Buy and Sell Stock II

购买股票，画出折线图找规律

## 123. Best Time to Buy and Sell Stock III

双向动态规划

## 125. Valid Palindrome

判回文字，这里本地和服务器的结果居然不一致！注意越界问题。isalnum, isalpha用法

## 133. Clone Graph

BFS: 队列+Map

## 136. Single Number

使用异或xor找出出现次数为奇数数字

## 137. Single Number 2

bit的规律

## 146. LRU Cache

LRU缓存的实现，双向链表+Hash map

## 155. Min Stack

双栈模拟Heap, 单栈记录diff

## 191. Number of 1 Bits

计算数字的1的个数
用n&(n-1)位运算，每次可以消掉一个1

## 198. House Robber

简单动态规划

## 207. Course Schedule

判断有向图是否有环

用拓扑算法

不需要判断节点是否被访问, 因为这个过程不会重复
`int count = qu.size();` 能减少4ms

## 208. Implement Trie (Prefix Tree)

字典树

## 202. Happy Number

用Slow, Fast指针检测链表是否存在环

## 283. Move Zeroes

In-place移动数字

## 303. Range Sum Query - Immutable

不变数组多次区间求和

## 338. Counting Bits

动态规划，数bits数

找规律，位运算

## 709. To Lower Case

变小写

## 771. Jewels and Stones

数组标记, 数组去重

## 848. Shifting Letters 

字母偏移，预先累加

## 874. Walking Robot Simulation

模拟题。注意审题，用hash降低复杂度

## 929. Unique Email Address

字符串处理，`s.erase(std::remove(s.begin(), s.end(), '.'), s.end());` 删除所有'.'字符

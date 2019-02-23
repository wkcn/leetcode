* 1. Two Sum

二重循环遍历

* 2. Add Two Numbers

链表求和，哨兵节点

* 3. Longest Substring Without Repeating Characters

最长没有重复字符的子序列

记录各字符最近一次出现的位置

* 4. Median of Two Sorted Arrays

求两有序数列的中位数，可泛化为求两有序数列的第k位数，二分法

* 5. Longest Palindromic Substring

最长回文子串，补符号，记忆

* 6. ZigZag Conversion

观察规律

* 7. Reverse Integer

翻转整数

* 8. String to Integer

解析字符串

* 9. Palindrome Number

回文数字

* 11. Container with Most Water

条形图最大面积，归纳法证明

* 12. Integer to Roman

找规律

* 13. Roman to Integer

找规律

* 14. Longest Common Prefix

最长公共前缀

* 15. 3Sum

O(n^2logn): 先对数组排序

选两个数，找第3个数

去重复数不会降低渐进复杂度

upper_bound的使用

O(n^2): 先对数组排序

三个数下标i, j, k

确定i, 调整j, k

去重做跳表能加速

* 16. 3Sum Closest

参考15. 3Sum

* 20. Valid Parenthess

括号匹配, 栈

* 21. Merge Two Sorted Lists

有序链表Merge

* 22. Generate Parenthess

递归生成

* 23. Merge K Sorted Lists 

有序链表Merge, 使用堆heap

* 125. Valid Palindrome

判回文字，这里本地和服务器的结果居然不一致！注意越界问题。isalnum, isalpha用法

* 709. To Lower Case

变小写

* 771. Jewels and Stones

数组标记, 数组去重

* 929. Unique Email Address

字符串处理，s.erase(std::remove(s.begin(), s.end(), '.'), s.end()); 删除所有'.'字符

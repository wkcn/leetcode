package main

import "fmt"

func sumOddLengthSubarrays(arr []int) int {
    // 计算每个数字的出现次数
    ans := 0
    for i, v := range arr {
        // 用组合思想
        // 左边数字的个数
        left := i
        // 右边数字的个数
        right := len(arr) - 1 - i
        left_even := left / 2
        right_even := right / 2
        // 偶数可以包括0
        ans += v * ((left_even + 1) * (right_even + 1) + (left - left_even) * (right - right_even));
    }
    return ans
}

func main() {
    fmt.Println(sumOddLengthSubarrays([]int{1, 4, 2, 5, 3}));
}

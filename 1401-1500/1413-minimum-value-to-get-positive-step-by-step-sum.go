package main

import "fmt"

func min(a, b int) int {
    if a <= b {
        return a
    }
    return b
}

func minStartValue(nums []int) int {
    mi := nums[0]
    su := nums[0]
    for i := 1; i < len(nums); i++ {
        su += nums[i]
        mi = min(mi, su)
    }
    ans := -mi + 1
    if ans <= 0 {
        ans = 1
    }
    return ans
}

func main() {
    nums := []int{-3,2,-3,4,2}
    fmt.Println(minStartValue(nums))
}

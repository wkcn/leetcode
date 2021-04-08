package main

import "fmt"

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func findMin(nums []int) int {
    lo, hi := 0, len(nums)
    ans := nums[0]
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[lo] == nums[mid] {
            ans = min(ans, nums[lo])  // 必须有
            lo++
        } else {
            if nums[lo] < nums[mid] {
                ans = min(ans, nums[lo])  // 必须有
                lo = mid + 1
            } else {
                ans = min(ans, nums[mid])
                hi = mid
            }
        }
    }
    return ans
}

func main() {
    fmt.Println(findMin([]int{3, 5, 1}))
    // fmt.Println(findMin([]int{2,2,2,0,1}))
}

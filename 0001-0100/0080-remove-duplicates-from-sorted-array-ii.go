package main

import "fmt"

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func removeDuplicates(nums []int) int {
    k := 0
    i := 0
    for i < len(nums) {
        // [i, j)是同样数字的区间
        j := i + 1
        for j < len(nums) {
            if nums[i] != nums[j] {
                break
            }
            j++
        }
        c := min(j - i, 2)
        for h := 0; h < c; h++ {
            nums[k] = nums[j - 1]
            k++
        }
        i = j
    }
    return k
}

func main() {
    nums := []int{0, 0, 1, 1, 1, 1, 2, 3, 3}
    fmt.Println(removeDuplicates(nums))
    fmt.Println(nums)
}

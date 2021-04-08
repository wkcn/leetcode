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
            if nums[mid] == nums[hi - 1] {
                ans = min(ans, nums[lo])
                lo++
                hi--
            } else {
                ans = min(ans, nums[lo])
                lo = mid + 1
            }
        } else {
            if nums[lo] < nums[mid] {
                ans = min(ans, nums[lo])
                lo = mid + 1
            } else {
                lo++
            }
        }
    }
    return ans
}

func main() {
    fmt.Println(findMin([]int{3,4,5,1,2}))
    fmt.Println(findMin([]int{4,5,6,7,0,1,2}))
    fmt.Println(findMin([]int{1,2,3,4}))
}

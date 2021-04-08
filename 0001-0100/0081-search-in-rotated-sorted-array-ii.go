package main
import "fmt"

func search(nums []int, target int) bool {
    lo, hi := 0, len(nums)
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[mid] == target {
            return true
        }
        // 多了判断相等的条件
        if nums[lo] == nums[mid] {
            if nums[mid] == nums[hi - 1] {
                // 左右都相等
                lo++
                hi--
            } else {
                lo = mid + 1
            }
        } else {
            // target != nums[mid]
            if nums[lo] < nums[mid] {
                if nums[lo] <= target && target < nums[mid] {
                    hi = mid
                } else {
                    lo = mid + 1
                }
            } else {
                if nums[mid] < target && target <= nums[hi - 1] {
                    lo = mid + 1
                } else {
                    hi = mid
                }
            }
        }
    }
    return false
}

func main() {
    fmt.Println(search([]int{2,5,6,0,0,1,2}, 0))
    fmt.Println(search([]int{2,5,6,0,0,1,2}, 6))
    fmt.Println(search([]int{2,5,6,0,0,1,2}, 3))
    fmt.Println(search([]int{2,5,6,0,0,1,2}, 4))
}

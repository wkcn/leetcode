// 好题, 需要考虑清特殊情况
package main
import "fmt"

// 注意判断条件中的等于号
func search(nums []int, target int) int {
    lo, hi := 0, len(nums)
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[mid] == target {
            return mid
        }
        if nums[lo] <= nums[mid] {
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
    return -1
}

// 注意判断条件中的等于号
func search3(nums []int, target int) int {
    lo, hi := 0, len(nums)
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[mid] == target {
            return mid
        }
        if nums[0] <= nums[mid] {
            if nums[0] <= target && target < nums[mid] {
                hi = mid
            } else {
                lo = mid + 1
            }
        } else {
            if nums[mid] < target && target <= nums[len(nums) - 1] {
                lo = mid + 1
            } else {
                hi = mid
            }
        }
    }
    return -1
}

func search2(nums []int, target int) int {
    lo, hi := 0, len(nums)
    // 先找到旋转中心，再二分搜索
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[0] < nums[mid] {
            lo = mid + 1
        } else {
            // 注意此时mid可能是旋转点
            if mid > 0 && nums[mid - 1] > nums[mid] {
                lo = mid
            }
            hi = mid
        }
    }
    // 这里需要注意等于的条件
    if target >= nums[0] {
        lo = 0
    } else {
        hi = len(nums)
    }
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if nums[mid] < target {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    if lo != len(nums) && nums[lo] == target {
        return lo
    }
    return -1
}

func main() {
    fmt.Println(search([]int{1, 3}, 1));
    fmt.Println(search([]int{3, 1}, 1));
    fmt.Println(search([]int{4,5,6,7,0,1,2}, 0));
    fmt.Println(search([]int{4,5,6,7,0,1,2}, 3));
}

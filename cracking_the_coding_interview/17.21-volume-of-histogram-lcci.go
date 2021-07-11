package main

import "fmt"


func trap3(height []int) int {
    /*
        water[i] = min(max(height[:i]), max(height[i+1:])) - height[i] 
     */
    if len(height) == 0 {
        return 0
    }
    ans := 0
    st := make([]int, 0)
    for i, h := range height {
        for len(st) > 0 && h >= height[st[len(st) - 1]] {
            ti := st[len(st) - 1]
            st = st[:len(st) - 1]
            if len(st) == 0 {
                break
            }
            left := st[len(st) - 1]
            dh := min(height[left], height[i]) - height[ti]
            ans += dh * (i - left - 1)
        }
        st = append(st, i)
    }
    return ans
}

// 双指针
func trap(height []int) int {
    if len(height) <= 2 {
        return 0
    }
    left, right := 0, len(height) - 1
    left_max, right_max := height[left], height[right]
    ans := 0
    for left < right {
        if left_max <= right_max {
            ans += left_max - height[left]
            left += 1
            left_max = max(left_max, height[left])
        } else {
            ans += right_max - height[right]
            right -= 1
            right_max = max(right_max, height[right])
        }
    }
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func trap2(height []int) int {
    /*
        water[i] = min(max(height[:i]), max(height[i+1:])) - height[i] 
     */
    if len(height) <= 2 {
        return 0
    }
    ans := 0
    left := make([]int, len(height))
    right := make([]int, len(height))

    left[0] = height[0]
    for i := 1; i < len(height); i++ {
        left[i] = max(left[i - 1], height[i])
    }
    right[len(height) - 1] = height[len(height) - 1]
    for i := len(height) - 2; i >= 0; i-- {
        right[i] = max(right[i + 1], height[i])
    }
    for i := 1; i < len(height) - 1; i++ {
        ans += min(left[i], right[i]) - height[i]
    }

    return ans
}


func main() {
    height := []int{0,1,0,2,1,0,1,3,2,1,2,1}
    fmt.Println(trap(height))
}

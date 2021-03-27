package main

import "fmt"

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a < b {
        return b
    }
    return a
}

func countGoodTriplets(arr []int, a int, b int, c int) int {
    // 枚举j和k
    cnt := 0
    // presum[v]表示值小于v的元素数量
    // [left, right]的数量: presum[right + 1] - presum[left]
    var presum [1002]int;
    // j 设成0是为了第一次前缀和
    for j := 0; j < len(arr) - 1; j++ {
        for k := j + 1; k < len(arr); k++ {
            if abs(arr[j] - arr[k]) <= b {
                // -a + arr[j] <= arr[i] <= a + arr[j]
                // -c + arr[k] <= arr[i] <= c + arr[k]
                left := max(arr[j] - a, arr[k] - c)
                left = max(0, left);
                right := min(arr[j] + a, arr[k] + c)
                right = min(1000, right);
                for i:= 0; i < j; i++ {
                    if left <= arr[i] && arr[i] <= right {
                        cnt += 1
                    }
                }
                // [left, right]
                if left <= right {
                    for i:= 0; i < j; i++ {
                        if arr[i] >= left && arr[i] <= right {
                            // cnt += 1
                        }
                    }
                    // cnt += presum[right + 1] - presum[left]
                }
            }
        }
        // 把arr[j]加上
        for t := arr[j] + 1; t <= 1001; t++ {
            presum[t] += 1
        }
    }
    return cnt
}

func countGoodTriplets2(arr []int, a int, b int, c int) int {
    cnt := 0
    for i := 0; i < len(arr) - 2; i++ {
        for j := i + 1; j < len(arr) - 1; j++ {
            for k := j + 1; k < len(arr); k++ {
                if abs(arr[i] - arr[j]) <= a &&
                    abs(arr[j] - arr[k]) <= b &&
                    abs(arr[i] - arr[k]) <= c {
                    cnt += 1
                }
            }
        }
    }
    return cnt
}

func main() {
    fmt.Println(countGoodTriplets([]int{3, 0, 1, 1, 9, 7}, 7, 2, 3))
    fmt.Println(countGoodTriplets([]int{7,3,7,3,12,1,12,2,3}, 5, 8, 1));  // 12
}

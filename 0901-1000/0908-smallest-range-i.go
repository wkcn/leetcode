package main

import "fmt"

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a < b {
        return b
    }
    return a
}

func smallestRangeI(A []int, K int) int {
    if len(A) <= 1 {
        return 0
    }
    mi := A[0]
    ma := A[0]
    for i := 1; i < len(A); i++ {
        mi = min(mi, A[i])
        ma = max(ma, A[i])
    }
    d := ma - mi
    return max(0, d - K * 2)
}

func main() {
    fmt.Println(smallestRangeI([]int{0, 10}, 2))
    fmt.Println(smallestRangeI([]int{1, 3, 6}, 3))
    fmt.Println(smallestRangeI([]int{2, 7, 2}, 1))
}

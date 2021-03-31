package main

import "fmt"

func searchMatrix(matrix [][]int, target int) bool {
    rows := len(matrix)
    if rows == 0 {
        return false
    }
    cols := len(matrix[0])
    if cols == 0 {
        return false
    }
    n := rows * cols
    lo, hi := 0, n
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        r, c := mid / cols, mid % cols
        if matrix[r][c] < target {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    return lo < n && matrix[lo / cols][lo % cols] == target
}

func main() {
    matrix := [][]int{{1,3,5,7},{10,11,16,20},{23,30,34,60}}
    target := 3
    fmt.Println(searchMatrix(matrix, target))
}

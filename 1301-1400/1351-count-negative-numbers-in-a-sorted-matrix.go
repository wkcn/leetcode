package main

import "fmt"

func countNegatives2(grid [][]int) int {
    // 从右上角到左下角
    rows := len(grid)
    if rows == 0 {
        return 0
    }
    cols := len(grid[0])
    if cols == 0 {
        return 0
    }
    c := cols - 1
    ans := 0
    for r := 0; r < rows; r++ {
        for c >= 0 && grid[r][c] < 0 {
            c--
        }
        ans += cols - c - 1
    }
    return ans
}

func countNegatives(grid [][]int) int {
    // 从右上角到左下角
    rows := len(grid)
    if rows == 0 {
        return 0
    }
    cols := len(grid[0])
    if cols == 0 {
        return 0
    }
    c := cols - 1
    ans := 0
    for r := 0; r < rows; r++ {
        lo, hi := 0, c + 1
        for lo < hi {
            mid := lo + ((hi - lo) >> 1)
            if grid[r][mid] >= 0 {
                lo = mid + 1
            } else {
                hi = mid
            }
        }
        ans += cols - lo
    }
    return ans
}

func main() {
    grid := [][]int{{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}}
    fmt.Println(countNegatives(grid)) // 8
}

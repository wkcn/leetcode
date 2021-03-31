package main

import "fmt"

func get_power(row []int) int {
    lo, hi := 0, len(row)
    for lo < hi {
        mid := lo + ((hi - lo) >> 1)
        if row[mid] == 1 {
            lo = mid + 1
        } else {
            hi = mid
        }
    }
    return lo
}

func topk_sort_impl(data []int, k int, cmp_func func(int, int)bool, lo int, hi int) {
    if lo < hi {
        pv := data[lo]
        left, right := lo, hi - 1
        for left < right {
            for left < right && !cmp_func(data[right], pv) {
                right--
            }
            data[left] = data[right]
            for left < right && !cmp_func(pv, data[left]) {
                left++
            }
            data[right] = data[left]
        }
        data[left] = pv
        // left == right
        // 左边无论如何都要排序
        topk_sort_impl(data, k, cmp_func, lo, left)
        if k > left + 1 {
            // 右边
            topk_sort_impl(data, k, cmp_func, left + 1, hi)
        }
    }
}

func topk_sort(data []int, k int, cmp_func func(int, int)bool) {
    topk_sort_impl(data, k, cmp_func, 0, len(data))
}

func kWeakestRows(mat [][]int, k int) []int {
    rows := len(mat)
    powers := make([]int, rows)
    for i, v := range mat {
        powers[i] = get_power(v)
    }
    idx := make([]int, rows)
    for i := 0; i < rows; i++ {
        idx[i] = i
    }
    cmp_func := func (a int, b int) bool {
        return powers[a] < powers[b] || (powers[a] == powers[b] && a < b)
    }
    topk_sort(idx, k, cmp_func)
    return idx[:k]
}

func main() {
    if true {
        mat := [][]int{{1,1,0,0,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,1,1,1,1}}
        k := 3
        fmt.Println(kWeakestRows(mat, k))
    }

    if true {
        mat := [][]int{{1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0}}
        k := 2
        fmt.Println(kWeakestRows(mat, k))
    }

    {
        mat := [][]int{{1,1,0},{1,1,0},{1,1,1},{1,1,1},{0,0,0},{1,1,1},{1,0,0}}
        k := 6
        fmt.Println(kWeakestRows(mat, k))
    }
}

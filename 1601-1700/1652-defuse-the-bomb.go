package main

import "fmt"

func decrypt(code []int, k int) []int {
    ans := make([]int, len(code))
    if k > 0 {
        su := 0
        for i := 1; i <= k; i++ {
            su += code[i]
        }
        ans[0] = su
        for i := 1; i < len(code); i++ {
            su = su - code[i] + code[(i + k) % len(code)]
            ans[i] = su
        }
    } else if k < 0 {
        su := 0
        for i := -1; i >= k; i-- {
            su += code[len(code) + i]
        }
        ans[0] = su
        for i := 1; i < len(code); i++ {
            su = su + code[i - 1] - code[(len(code) + i + k - 1) % len(code)]
            ans[i] = su
        }
    }
    return ans
}

func main() {
    {
        code := []int{5, 7, 1, 4}
        k := 3
        fmt.Println(decrypt(code, k))
    }
    {
        code := []int{2, 4, 9, 3}
        k := -2
        fmt.Println(decrypt(code, k))
    }
}

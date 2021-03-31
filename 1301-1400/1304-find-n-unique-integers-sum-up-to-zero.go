package main

import "fmt"

func sumZero(n int) []int {
    ans := make([]int, 0, n)
    for i := 1; i <= n / 2; i++ {
        ans = append(ans, i)
        ans = append(ans, -i)
    }
    if n % 2 == 1 {
        ans = append(ans, 0)
    }
    return ans
}

func main() {
    fmt.Println(sumZero(5))
    fmt.Println(sumZero(3))
}

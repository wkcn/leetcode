package main

import "fmt"

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

func clumsy(N int) int {
    /*
        f(1) = 1
        f(2) = 2 * 1
        f(3) = 3 * 2 / 1
        f(4) = 4 * 3 / 2 + 1
        f(5) = 5 * 4 / 3 + 2 - 1
        f(6) = 6 * 5 / 4 + 3 - 2 * 1
        f(7) = 7 * 6 / 5 + 4 - 3 * 2 / 1
        f(8) = 8 * 7 / 6 + 5 - 4 * 3 / 2 + 1
        f(9) = 9 * 8 / 7 + 6 - 5 * 4 / 3 + 2 - 1
        f(10) = (10 * 9 / 8) + 7 - (6 * 5 / 4) + 3 - (2 * 1)
     */
     // 4 个一组
     su := 0
     for n := N; n >= 0; n -= 4 {
         v := n * max(1, n - 1) / max(1, n - 2)
         b := max(n - 3, 0)
         if n == N {
             su = su + v + b
         } else {
             su = su - v + b
         }
     }
     return su
}

func main() {
    fmt.Println(clumsy(0))
    fmt.Println(clumsy(1))
    fmt.Println(clumsy(2))
    fmt.Println(clumsy(3))
    fmt.Println(clumsy(4)) // 7
    fmt.Println(clumsy(10)) // 12
}

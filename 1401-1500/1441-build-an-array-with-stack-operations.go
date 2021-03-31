package main

import "fmt"

func buildArray(target []int, n int) []string {
    ans := make([]string, 0)
    i := 1
    for j := 0; j < len(target); j++ {
        for i < target[j] {
            ans = append(ans, "Push")
            ans = append(ans, "Pop")
            i += 1
        }
        ans = append(ans, "Push")
        i += 1
    }
    return ans
}

func main() {
    fmt.Println(buildArray([]int{1, 3}, 3))
}

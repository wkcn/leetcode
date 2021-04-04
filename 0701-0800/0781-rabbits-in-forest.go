package main

import "fmt"

func numRabbits(answers []int) int {
    // 同样颜色报同样的数字，但同样数字不一定是同样颜色
    // 把报同样数字的归到一组
    cnts := make(map[int]int)
    for _, v := range answers {
        cnts[v] += 1
    }
    ans := 0
    for k, v := range cnts {
        g := k + 1
        ans += (v + g - 1) / g * g
    }
    return ans
}

func main() {
    fmt.Println(numRabbits([]int{1, 1, 2}))
    fmt.Println(numRabbits([]int{10, 10, 10}))
    fmt.Println(numRabbits([]int{}))
}

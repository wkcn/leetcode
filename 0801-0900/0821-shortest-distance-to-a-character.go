package main

import ("fmt"
        "math")

func shortestToChar2(s string, c byte) []int {
    ans := make([]int, len(s))
    for i := 0; i < len(s); i++ {
        ans[i] = -1
    }
    var q []int
    for i := 0; i < len(s); i++ {
        if s[i] == c {
            q = append(q, i)
            ans[i] = 0
        }
    }
    step := 0
    for len(q) > 0 {
        step += 1
        for e := len(q); e > 0; e-- {
            head := q[0]
            q = q[1:]
            for _, offset := range [2]int{-1, 1} {
                x := head + offset
                if uint(x) < uint(len(s)) && ans[x] == -1 {
                    ans[x] = step
                    q = append(q, x)
                }
            }
        }
    }
    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func shortestToChar(s string, c byte) []int {
    ans := make([]int, len(s))
    prev := math.MinInt32 
    for i, ch := range(s) {
        if byte(ch) == c {
            prev = i
        }
        ans[i] = i - prev
    }
    prev = math.MaxInt32
    for i := len(s) - 1; i >= 0; i-- {
        if byte(s[i]) == c {
            prev = i;
        }
        ans[i] = min(ans[i], prev - i)
    }
    return ans
}

func main() {
    s := "loveleetcode"
    c := byte('e')
    fmt.Println(shortestToChar(s, c))
}

package main

import "fmt"

func numberOfLines(widths []int, s string) []int {
    const max_len = 100
    if len(s) == 0 {
        return []int{0, 0}
    }
    n := 1
    w := 0
    for _, c := range s {
        v := widths[c - 'a']
        if w + v > max_len {
            n += 1
            w = v
        } else {
            w += v
        }
    }
    return []int{n, w}
}

func main() {
    widths := []int{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10}
    S := "bbbcccdddaaa"
    fmt.Println(numberOfLines(widths, S))
}

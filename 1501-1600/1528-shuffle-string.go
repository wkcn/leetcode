package main

import "fmt"

/*
func restoreString(s string, indices []int) string {
    out := make([]byte, len(s))
    for i, j := range indices {
        out[j] = s[i]
    }
    return string(out)
}
*/

// inplace
func restoreString(s string, indices []int) string {
    out := make([]rune, len(s))
    for i, c := range s {
        out[i] = c
    }
    for i := 0; i < len(s); i++ {
        j := i
        d := out[j]
        for indices[j] != j {
            g := indices[j]
            c := out[g]
            out[g] = d
            d = c
            indices[j] = j
            j = g
        }
    }
    return string(out)
}

func main() {
    s := "codeleet"
    indices := []int{4, 5, 6, 7, 0, 2, 1, 3}
    fmt.Println(restoreString(s, indices))
}

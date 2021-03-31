package main

import ("fmt"; "strings")

func generateTheString(n int) string {
    if n % 2 == 0 {
        return "a" + strings.Repeat("b", n - 1)
    }
    return strings.Repeat("b", n)
}

func main() {
    fmt.Println(generateTheString(3))
    fmt.Println(generateTheString(4))
}

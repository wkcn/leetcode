package main

import "fmt"

func freqAlphabets(s string) string {
    ans := []byte{}
    i := 0
    for i < len(s) {
        if i + 2 < len(s) && s[i + 2] == '#' {
            ans = append(ans, 'j' + (s[i] - '0') * 10 + (s[i + 1] - '0') - 10)
            i += 3
        } else {
            ans = append(ans, 'a' + s[i] - '1')
            i += 1
        }
    }
    return string(ans)
}

func main() {
    s := "10#11#12"
    fmt.Println(freqAlphabets(s))
}

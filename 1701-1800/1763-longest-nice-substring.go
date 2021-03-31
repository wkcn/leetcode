package main

import "fmt"

func longestNiceSubstring(s string) string {
    ans := ""
    longestNiceSubstringImpl(&s, 0, len(s), &ans)
    return ans
}

func alpha2id(c byte) int {
    if c >= 'a' && c <= 'z' {
        return int(c - 'a')
    }
    return int(c - 'A')
}

func longestNiceSubstringImpl(s *string, start int, end int, ans *string) {
    lo, up := 0, 0
    for i := start; i < end; i++ {
        c := (*s)[i]
        if c >= 'a' && c <= 'z' {
            lo |= 1 << (c - 'a')
        } else {
            up |= 1 << (c - 'A')
        }
    }
    mask := lo ^ up
    split := -1
    for i := 0; i < 26; i++ {
        if mask & (1 << i) != 0 {
            split = i
            break
        }
    }
    if split == -1 {
        if end - start > len(*ans) {
            *ans = (*s)[start:end]
        }
        return
    }
    left := start
    for left < end {
        for left < end && alpha2id((*s)[left]) == split {
            left++
        }
        if left == end {
            break
        }
        right := left + 1
        for right < end && alpha2id((*s)[right]) != split {
            right++;
        }
        longestNiceSubstringImpl(s, left, right, ans)
        left = right;
    }
}

func main() {
    fmt.Println(longestNiceSubstring("YazaAay"))
    fmt.Println(longestNiceSubstring("Bb"))
    fmt.Println(longestNiceSubstring("c"))
}

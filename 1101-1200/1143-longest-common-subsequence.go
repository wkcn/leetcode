package main

import "fmt"

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}

func longestCommonSubsequence(text1 string, text2 string) int {
    len1 := len(text1)
    len2 := len(text2)
    if len1 > len2 {
        return longestCommonSubsequence(text2, text1)
    }
    dp := make([]int, len1 + 1)
    for j := 0; j < len2; j++ {
        lt := 0
        for i := 0; i < len1; i++ {
            old := dp[i + 1]
            if text1[i] == text2[j] {
                dp[i + 1] = lt + 1
            } else {
                dp[i + 1] = max(dp[i + 1], dp[i])
            }
            lt = old
        }
    }
    return dp[len1]
}

func longestCommonSubsequence2(text1 string, text2 string) int {
    len1 := len(text1)
    len2 := len(text2)
    dp := make([][]int, len1 + 1)
    for i := 0; i <= len1; i++ {
        dp[i] = make([]int, len2 + 1)
    }
    for i := 0; i < len1; i++ {
        for j := 0; j < len2; j++ {
            if text1[i] == text2[j] {
                dp[i + 1][j + 1] = dp[i][j] + 1
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])
            }
        }
    }
    return dp[len1][len2]
}

func main() {
    text1 := "abcde"
    text2 := "ace"
    fmt.Println(longestCommonSubsequence(text1, text2))
}

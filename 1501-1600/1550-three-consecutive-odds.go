package main

import "fmt"

func threeConsecutiveOdds(arr []int) bool {
    cnt := 0
    for _, v := range arr {
        if v % 2 == 0 {
            cnt = 0
        } else {
            cnt += 1
            if cnt >= 3 {
                return true
            }
        }
    }
    return false
}

func main() {
    fmt.Println(threeConsecutiveOdds([]int{2,6,4,1}));
    fmt.Println(threeConsecutiveOdds([]int{2,6,4,1,3,5,4}));
}

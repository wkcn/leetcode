package main

import "fmt"

func busyStudent(startTime []int, endTime []int, queryTime int) int {
    cnt := 0
    t := len(startTime)
    for i := 0; i < t; i++ {
        if queryTime >= startTime[i] && queryTime <= endTime[i] {
            cnt += 1
        }
    }
    return cnt
}

func main() {
    startTime := []int{1, 2, 3}
    endTime := []int{3, 2, 7}
    queryTime := 4
    fmt.Println(busyStudent(startTime, endTime, queryTime))
}

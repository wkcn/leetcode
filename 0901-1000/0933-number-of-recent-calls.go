package main

import "fmt"

type RecentCounter struct {
    q []int
}


func Constructor() RecentCounter {
    q := []int{}
    return RecentCounter{q: q}
}


func (this *RecentCounter) Ping(t int) int {
    const T = 3000
    for len(this.q) > 0 && this.q[0] + T < t {
        this.q = this.q[1:]
    }
    this.q = append(this.q, t)
    return len(this.q)
}


func main() {
    obj := Constructor();
    fmt.Println(obj.Ping(1))
    fmt.Println(obj.Ping(100))
    fmt.Println(obj.Ping(3001))
    fmt.Println(obj.Ping(3002))
 }

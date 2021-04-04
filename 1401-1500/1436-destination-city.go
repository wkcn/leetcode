package main

import "fmt"

func destCity(paths [][]string) string {
    // 终点出度为0
    deg := make(map[string]int)
    for _, path := range paths {
        src := path[0]
        deg[src] += 1
    }
    for _, path := range paths {
        dst := path[1]
        if _, ok := deg[dst]; !ok {
            return dst
        }
    }
    return ""
}

func main() {
    paths := [][]string{{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}}
    fmt.Println(destCity(paths))
}

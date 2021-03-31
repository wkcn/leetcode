package main
import "fmt"
import "sort"

type ii struct {
    k int
    v int
}

func subsetsWithDup2(nums []int) [][]int {
    cnts := make(map[int]int)
    for _, x := range nums {
        cnts[x] += 1
    }
    cnts_vec := make([]ii, 0)
    for k, v := range cnts {
        cnts_vec = append(cnts_vec, ii{k, v})
    }
    ans := make([][]int, 0)
    buf := make([]int, 0)
    run(&cnts_vec, 0, &ans, &buf)
    return ans
}

func run(cnts *[]ii, i int, ans *[][]int, buf *[]int) {
    if i >= len(*cnts) {
        var tmp []int
        for _, x := range *buf {
            tmp = append(tmp, x)
        }
        *ans = append(*ans, tmp)
        return
    }
    run(cnts, i + 1, ans, buf)
    for j:= 0; j < (*cnts)[i].v; j++ {
        *buf = append(*buf, (*cnts)[i].k)
        run(cnts, i + 1, ans, buf)
    }
    *buf = (*buf)[:len(*buf)-(*cnts)[i].v]
}

func subsetsWithDup(nums []int) (ans [][]int) {
    sort.Ints(nums)
    var buf []int
    runs(nums, 0, &buf, &ans)
    return
}

func runs(nums []int, start int, buf *[]int, ans *[][]int) {
    tmp := make([]int, len(*buf))
    copy(tmp, *buf)
    *ans = append(*ans, tmp)
    for i := start; i < len(nums); i++ {
        if i > start && nums[i - 1] == nums[i] {
            continue
        }
       *buf = append(*buf, nums[i])
       runs(nums, i + 1, buf, ans)
       *buf = (*buf)[:len(*buf) - 1]
    }
}


func main() {
    nums := []int{1, 2, 2}
    fmt.Println(subsetsWithDup(nums))
}

package main
import "fmt"

type TreeNode struct {
  Val int
  Left *TreeNode
  Right *TreeNode
}

func deepestLeavesSum(root *TreeNode) int {
    if root == nil {
        return 0
    }
    type TL struct {
        node *TreeNode
        height int
    }
    var st [](TL)
    st = append(st, TL{root, 1})
    max_height := 0
    su := 0
    for len(st) > 0 {
        t := st[len(st) - 1]
        st = st[:len(st) - 1]
        if t.height == max_height {
            su += t.node.Val
        } else if t.height > max_height {
            su = t.node.Val
            max_height = t.height
        }
        if t.node.Left != nil {
            st = append(st, TL{t.node.Left, t.height + 1})
        }
        if t.node.Right != nil {
            st = append(st, TL{t.node.Right, t.height + 1})
        }
    }
    return su
}

func main() {
    t := TreeNode{1, nil, nil}
    fmt.Println(deepestLeavesSum(&t))
}

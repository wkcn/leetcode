/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) int {
    su := 0
    for head != nil {
        su = su * 2 + head.Val
        head = head.Next
    }
    return su
}

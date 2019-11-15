# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        if pHead is None:
            return None
        p, c = None, pHead
        while c:
            tmp = c.next
            c.next = p
            p = c
            c = tmp
        return p

def PrintList(r):
    while r:
        print(r.val, end=', ') 
        r = r.next

if __name__ == '__main__':
    data = input()
    data = [int(x) for x in data.split()]
    num_node = len(data)

    nodes = [ListNode(x) for x in data]
    for i in range(num_node-1):
        nodes[i].next = nodes[i+1]

    pHead = nodes[0] if num_node > 0 else None
    PrintList(Solution().ReverseList(pHead))

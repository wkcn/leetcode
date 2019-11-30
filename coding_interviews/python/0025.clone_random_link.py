# -*- coding:utf-8 -*-
class RandomListNode:
   def __init__(self, x):
       self.label = x
       self.next = None
       self.random = None

class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        if pHead is None:
             return None
        ma = dict()
        ma[None] = None
        r = pHead
        while r:
            ma[r] = RandomListNode(r.label)
            r = r.next
        r = pHead
        while r:
            ma[r].next = ma[r.next] 
            ma[r].random = ma[r.random]
            r = r.next
        return ma[pHead]

def PrintList(r):
    while r:
        print(r.random.label if r.random else 0, end=', ') 
        r = r.next

if __name__ == '__main__':
    data = input()
    data = [int(x) for x in data.split()]
    num_node = len(data)
    nodes = [RandomListNode(x) for x in range(num_node)]
    for i in range(num_node-1):
        nodes[i].next = nodes[i+1]
    for i, t in enumerate(data):
        if t > 0:
            assert t < num_node
            nodes[i].random = nodes[t]
    pHead = nodes[0] if num_node > 0 else None
    PrintList(Solution().Clone(pHead))

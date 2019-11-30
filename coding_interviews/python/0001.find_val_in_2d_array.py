# -*- coding:utf-8 -*-
import queue

class Solution:
    # array 二维列表
    def Find(self, target, array):
        rows = len(array)
        if rows == 0:
            return False
        cols = len(array[0])
        if cols == 0:
            return False
        # write code here
        q = queue.Queue()
        q.put((0, 0, rows, cols)) 
        while not q.empty():
            w = q.get()
            if w[0] >= w[2] or w[1] >= w[3]:
                continue
            mr = w[0] + (w[2] - w[0]) // 2
            mc = w[1] + (w[3] - w[1]) // 2
            v = array[mr][mc]
            if v == target:
                return True 
            elif v < target:
                q.put((w[0], mc+1, mr+1, w[3]))
                q.put((mr+1, w[1], w[2], mc+1))
                q.put((mr+1, mc+1, w[2], w[3]))
            else:
                q.put((w[0], w[1], mr, mc))
                q.put((w[0], mc, mr, w[3]))
                q.put((mr, w[1], w[2], mc))
        return False


def get_inputs():
    s = input()
    data = [int(x) for x in s.split()]
    return data

if __name__ == '__main__':
    rows, cols = get_inputs() 
    data = get_inputs()
    assert len(data) == rows * cols
    array = [[None] * cols] * rows
    for r in range(rows):
        for c in range(cols):
            array[r][c] = data[r * cols + c]
    target = int(input())
    print(Solution().Find(target, array))

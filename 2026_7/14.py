"""
https://atcoder.jp/contests/abc217/tasks/abc217_e

一开始，有一个空数组 a。
输入 q(1≤n≤2e5) 和 q 个询问，格式如下：
"1 x"：把 x(1≤x≤1e9) 插到 a 的末尾。
"2"：输出 a[0]，然后移除 a[0]。保证此时 a 不为空。
"3"：把 a 从小到大排序。

思路：

把这一堆元素分成两部分来维护，第一部分是已经排序的元素，第二部分是未排序的元素。
由于已经排序的元素一定在这个数组的前半部分，所以操作2就是弹出第一部分的最小值，操作3就是把第二部分全部放到第一部分
如果执行操作2的时候第一部分为空，就需要移除第二部分的最前面的元素

观察可以知道，第一部分使用堆来维护，第二部分使用队列来维护
"""

import heapq
from collections import deque

q = int(input())
heap_part1 = []
dq_part2 = deque()

for _ in range(q):
    op = list(map(int, input().split()))
    if op[0] == 1:
        dq_part2.append(op[1])
    elif op[0] == 2:
        if len(heap_part1):
            print(heapq.heappop(heap_part1))
        else:
            print(dq_part2.popleft())
    else:
        while len(dq_part2):
            heapq.heappush(heap_part1, dq_part2.pop())



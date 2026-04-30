from collections import Counter, defaultdict, deque
from math import gcd, sqrt
from bisect import bisect_left, bisect_right
from functools import lru_cache
import sys

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    c = []
    d = []
    ans = []
    for x in a:
        if x % 2 == 0 and x % 3 == 0:
            ans.append(x)
        elif x % 2 == 0:
            b.append(x)
        elif x % 3 == 0:
            d.append(x)
        else:
            c.append(x)
    ans += b
    ans += c
    ans += d
    print(*ans)

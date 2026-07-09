"""
https://atcoder.jp/contests/abc406/tasks/abc406_c

输入 n(4≤n≤3e5) 和 1~n 的排列 a。

定义波浪数组 b，满足：
1. len(b) >= 4。
2. b[0] < b[1]。
3. 恰好有一个 i 满足 b[i-1] < b[i] > b[i+1]。
4. 恰好有一个 i 满足 b[i-1] > b[i] < b[i+1]。

输出 a 有多少个波浪子数组。
"""

n = int(input())
a = list(map(int, input().split()))
b = [i for i, v in enumerate(a) if i == 0 or i == n - 1 or
     (a[i - 1] < v > a[i + 1]) or (a[i - 1] > v < a[i + 1])]

ans = 0
for i in range(len(b) - 3):
    i, j, p, q = b[i], b[i + 1], b[i + 2], b[i + 3]
    if a[i] < a[j]:
        ans += (j - i) * (q - p)
print(ans)




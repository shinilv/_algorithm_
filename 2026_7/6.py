"""
https://atcoder.jp/contests/abc257/tasks/abc257_c
输入 n(1≤n≤2e5) 和长为 n 的 0-1 字符串和长为 n 的数组 a(1≤a[i]≤1e9)。
请你选择一个数 x，然后考察每个下标 i，如果满足 s[i]='0' 且 a[i] < x，或者 s[i]='1' 且 a[i] >= x，那么得到一分。
输出最大总得分。
"""

n = int(input())
s = input()
a = list(map(int, input().split()))

b, c = [a[i] for i, ch in enumerate(s) if ch == '1'], [a[i] for i, ch in enumerate(s) if ch == '0']

b.sort()
c.sort()
n, m = len(b), len(c)
b.insert(0, 0)

ans = max(n, m)

temp = -1
j = 0
for i in range(n):
    temp = b[i + 1]
    while j < m and c[j] < temp:
        j += 1
    ans = max(ans, n - i + j)
print(ans)

"""
https://atcoder.jp/contests/abc265/tasks/abc265_d
输入 n(3≤n≤2e5) p(1≤p≤1e15) q(1≤q≤1e15) r(1≤r≤1e15) 和长为 n 的数组 a(1≤a[i]≤1e9)。
把 a 分成五个子数组（可以为空），要求第二个子数组的和等于 p，第三个子数组的和等于 q，第四个子数组的和等于 r。
能否做到？输出 Yes 或 No。
思路：
设 a 的前缀和数组为 pre。
枚举 pre[i]，判断 pre[i]+p，pre[i]+p+q，pre[i]+p+q+r 是否在 pre 中。
"""

from collections import defaultdict
n, p, q, r = map(int, input().split())

a = list(map(int, input().split()))

pre = [0] * (n + 1)
mp = defaultdict(int)
for i in range(n):
    pre[i + 1] = pre[i] + a[i]
    mp[pre[i + 1]] = 1
ans = "No"
for i in range(0, n + 1):
    if mp[pre[i] + p] + mp[pre[i] + p + q] + mp[pre[i] + p + q + r] == 3:
        ans = "Yes"
        break
print(ans)


